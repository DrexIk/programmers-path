#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#define MAX_WORD_LEN 100
#define MAX_PATH_LEN 256

typedef struct {
    wchar_t word[MAX_WORD_LEN];
    int count;
} WordInfo;

int read_config(const char *config_name, char *in_name, char *out_name) {
    FILE *cfg = fopen(config_name, "r");
    if (cfg == NULL) {
        printf("Ошибка: Конфигурационный файл не найден.\n");
        return 0;
    }

    char line[MAX_PATH_LEN * 2];
    int found_in = 0;
    int found_out = 0;

    while (fgets(line, sizeof(line), cfg)) {
        char *delim = strchr(line, '=');
        if (delim != NULL) {
            *delim = '\0';
            char *key = line;
            char *val = delim + 1;

            size_t len = strlen(val);
            while (len > 0 && (val[len - 1] == '\n' || val[len - 1] == '\r' || val[len - 1] == ' ')) {
                val[len - 1] = '\0';
                len--;
            }
            while (*key == ' ') key++;
            char *key_end = key + strlen(key);
            while (key_end > key && *(key_end - 1) == ' ') {
                *(key_end - 1) = '\0';
                key_end--;
            }
            while (*val == ' ') val++;

            if (strcmp(key, "INPUT_FILE") == 0) {
                strncpy(in_name, val, MAX_PATH_LEN - 1);
                found_in = 1;
            } else if (strcmp(key, "OUTPUT_FILE") == 0) {
                strncpy(out_name, val, MAX_PATH_LEN - 1);
                found_out = 1;
            }
        }
    }

    fclose(cfg);
    return (found_in && found_out);
}

int process_text(FILE *fin, WordInfo **words_array, int *words_count) {
    wchar_t current_word[MAX_WORD_LEN];
    int char_idx = 0;
    wint_t ch;

    while ((ch = fgetwc(fin)) != WEOF) {
        if (iswalpha(ch)) {
            if (char_idx < MAX_WORD_LEN - 1) {
                current_word[char_idx++] = towlower(ch);
            }
        } else {
            if (char_idx > 0) {
                current_word[char_idx] = L'\0';
                int found = 0;

                for (int i = 0; i < *words_count; i++) {
                    if (wcscmp((*words_array)[i].word, current_word) == 0) {
                        (*words_array)[i].count++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    WordInfo *temp = realloc(*words_array, (*words_count + 1) * sizeof(WordInfo));
                    if (temp == NULL) {
                        printf("Ошибка: Не удалось выделить память во время обработки текста.\n");
                        return 0;
                    }
                    *words_array = temp;
                    wcscpy((*words_array)[*words_count].word, current_word);
                    (*words_array)[*words_count].count = 1;
                    (*words_count)++;
                }
                char_idx = 0;
            }
        }
    }

    if (char_idx > 0) {
        current_word[char_idx] = L'\0';
        int found = 0;
        for (int i = 0; i < *words_count; i++) {
            if (wcscmp((*words_array)[i].word, current_word) == 0) {
                (*words_array)[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            WordInfo *temp = realloc(*words_array, (*words_count + 1) * sizeof(WordInfo));
            if (temp != NULL) {
                *words_array = temp;
                wcscpy((*words_array)[*words_count].word, current_word);
                (*words_array)[*words_count].count = 1;
                (*words_count)++;
            }
        }
    }

    return 1;
}

#endif
