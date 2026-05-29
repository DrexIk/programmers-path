#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "analyzer.h"

int main() {
    setlocale(LC_ALL, "");

    char in_name[MAX_PATH_LEN] = {0};
    char out_name[MAX_PATH_LEN] = {0};

    printf("Программа запущена.\n");

    if (!read_config("config.txt", in_name, out_name)) {
        printf("Ошибка: Некорректный или отсутствующий файл config.txt\n");
        return 1;
    }

    printf("Конфигурация успешно загружена.\n");

    FILE *fin = fopen(in_name, "r");
    if (fin == NULL) {
        printf("Ошибка: Не удалось открыть входной файл %s\n", in_name);
        return 1;
    }

    FILE *fout = fopen(out_name, "w");
    if (fout == NULL) {
        printf("Ошибка: Не удалось создать выходной файл %s\n", out_name);
        fclose(fin);
        return 1;
    }

    WordInfo *words = NULL;
    int words_count = 0;

    if (!process_text(fin, &words, &words_count)) {
        printf("Ошибка во время обработки данных.\n");
        free(words);
        fclose(fin);
        fclose(fout);
        return 1;
    }

    for (int i = 0; i < words_count - 1; i++) {
        for (int j = 0; j < words_count - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                WordInfo temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < words_count; i++) {
        fwprintf(fout, L"%ls: %d\n", words[i].word, words[i].count);
    }

    free(words);
    fclose(fin);
    fclose(fout);

    printf("Анализ успешно завершен. Результаты сохранены в %s\n", out_name);
    printf("Программа успешно завершила работу.\n");
    return 0;
}
