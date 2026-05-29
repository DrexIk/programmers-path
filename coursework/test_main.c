#include <locale.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <cmocka.h>
#include "analyzer.h"

static void test_process_text(void **state) {
    WordInfo *test_words = NULL;
    int test_count = 0;

    FILE *test_input = fopen("test_temp.txt", "w+");
    assert_non_null(test_input);
    
    fwprintf(test_input, L"Привет привет Мир ");
    rewind(test_input);

    int result = process_text(test_input, &test_words, &test_count);
    assert_int_equal(result, 1);
    assert_int_equal(test_count, 2);

    int привет_idx = -1;
    for (int i = 0; i < test_count; i++) {
        if (wcscmp(test_words[i].word, L"привет") == 0) {
            привет_idx = i;
        }
    }

    assert_int_not_equal(привет_idx, -1);
    assert_int_equal(test_words[привет_idx].count, 2);

    free(test_words);
    fclose(test_input);
    remove("test_temp.txt");
}

static void test_read_config_missing(void **state) {
    char in_name[MAX_PATH_LEN] = {0};
    char out_name[MAX_PATH_LEN] = {0};
    
    int result = read_config("missing_config_file.txt", in_name, out_name);
    assert_int_equal(result, 0);
}

int main(void) {
    setlocale(LC_ALL, "");
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_process_text),
        cmocka_unit_test(test_read_config_missing),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
