#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Проверка, отсортирован ли массив по возрастанию */
int is_sorted(int arr[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) return 0;
    }
    return 1;
}

/* Сортировка прямым включением (Insertion Sort) с подсчётом пересылок (M) и сравнений (C) */
void insertion_sort(int arr[], int n, long long *m, long long *c) {
    int i, j, temp;
    *m = 0; *c = 0;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        (*m)++;                     /* пересылка temp */
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            (*c)++;                  /* сравнение (истинное) */
            arr[j+1] = arr[j];
            (*m)++;                  /* пересылка при сдвиге */
            j--;
        }
        if (j >= 0) (*c)++;          /* последнее сравнение (ложное) при j>=0 */
        arr[j+1] = temp;
        (*m)++;                      /* пересылка на место */
    }
}

/* Сортировка Шелла с заданной последовательностью шагов */
void shell_sort(int arr[], int n, int steps[], int step_count, long long *m, long long *c) {
    int s, i, j, temp, h;
    *m = 0; *c = 0;
    for (s = 0; s < step_count; s++) {
        h = steps[s];
        for (i = h; i < n; i++) {
            temp = arr[i];
            (*m)++;
            j = i - h;
            while (j >= 0 && arr[j] > temp) {
                (*c)++;
                arr[j + h] = arr[j];
                (*m)++;
                j -= h;
            }
            if (j >= 0) (*c)++;      /* ложное сравнение, если j>=0 */
            arr[j + h] = temp;
            (*m)++;
        }
    }
}

/* Генерация последовательности шагов по формуле Кнута (убывающая) */
void generate_knuth_steps(int n, int steps[], int *count) {
    int h = 1;
    while (h < n) {
        h = 3 * h + 1;
    }
    *count = 0;
    h = (h - 1) / 3;   /* возвращаемся к последнему шагу, меньшему n */
    while (h >= 1) {
        steps[(*count)++] = h;
        h = (h - 1) / 3;
    }
}

/* Генерация другой последовательности шагов: деление пополам (h = n/2, n/4, ..., 1) */
void generate_other_steps(int n, int steps[], int *count) {
    int h;
    *count = 0;
    h = n / 2;
    while (h >= 1) {
        steps[(*count)++] = h;
        h /= 2;
    }
}

/* Преобразование массива шагов в строку для вывода в таблицу */
void steps_to_string(int steps[], int count, char *buffer, size_t buf_size) {
    int i;
    char tmp[16];
    buffer[0] = '\0';
    for (i = 0; i < count; i++) {
        sprintf(tmp, "%d", steps[i]);
        strncat(buffer, tmp, buf_size - strlen(buffer) - 1);
        if (i < count - 1) {
            strncat(buffer, ",", buf_size - strlen(buffer) - 1);
        }
    }
}

int main() {
    /* Фиксированный seed для воспроизводимости результатов */
    srand(123);

    /* Наборы размеров массивов: теперь оба включают 100,200,300,400,500 */
    int ns[] = {100, 200, 300, 400, 500};
    int num_n = sizeof(ns) / sizeof(ns[0]);

    long long insert_m, insert_c, shell_m, shell_c, shell_other_m, shell_other_c;
    int i, j, n, step_count_knuth, step_count_other;
    int steps_knuth[100], steps_other[100];
    int *orig, *arr_insert, *arr_shell_knuth, *arr_shell_other;
    char knuth_str[100], other_str[100];

    /* ------------------------------------------------------------------ */
    /* Таблица 1: Сравнение InsertSort и ShellSort (шаги Кнута)           */
    /* ------------------------------------------------------------------ */
    printf("Таблица 1. Сравнение InsertSort и ShellSort (шаги по формуле Д.Кнута)\n");
    printf("+-----+--------------------------+----------------+----------------+\n");
    printf("| n   | h1...hm (Knuth)           | Insert Mф+Сф   | Shell Mф+Сф    |\n");
    printf("+-----+--------------------------+----------------+----------------+\n");

    for (i = 0; i < num_n; i++) {
        n = ns[i];
        /* Исходный массив */
        orig = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            orig[j] = rand() % 1000;
        }

        /* Insertion Sort */
        arr_insert = (int*)malloc(n * sizeof(int));
        memcpy(arr_insert, orig, n * sizeof(int));
        insertion_sort(arr_insert, n, &insert_m, &insert_c);
        if (!is_sorted(arr_insert, n)) printf("Ошибка: InsertSort не отсортировала массив (n=%d)\n", n);
        free(arr_insert);

        /* Shell Sort с шагами Кнута */
        generate_knuth_steps(n, steps_knuth, &step_count_knuth);
        arr_shell_knuth = (int*)malloc(n * sizeof(int));
        memcpy(arr_shell_knuth, orig, n * sizeof(int));
        shell_sort(arr_shell_knuth, n, steps_knuth, step_count_knuth, &shell_m, &shell_c);
        if (!is_sorted(arr_shell_knuth, n)) printf("Ошибка: ShellSort (Knuth) не отсортировала массив (n=%d)\n", n);
        free(arr_shell_knuth);

        /* Формируем строку с шагами */
        steps_to_string(steps_knuth, step_count_knuth, knuth_str, sizeof(knuth_str));

        printf("| %3d | %-24s | %14lld | %14lld |\n",
               n, knuth_str, insert_m + insert_c, shell_m + shell_c);

        free(orig);
    }
    printf("+-----+--------------------------+----------------+----------------+\n\n");

    /* ------------------------------------------------------------------ */
    /* Таблица 2: Сравнение двух последовательностей шагов для ShellSort  */
    /* ------------------------------------------------------------------ */
    printf("Таблица 2. Сравнение двух последовательностей шагов для ShellSort\n");
    printf("+-----+--------------------------+----------------+--------------------------+----------------+\n");
    printf("| n   | h1...hm (Knuth)           | Shell Mф+Сф    | h1...hm (другая)         | Shell Mф+Сф    |\n");
    printf("+-----+--------------------------+----------------+--------------------------+----------------+\n");

    for (i = 0; i < num_n; i++) {
        n = ns[i];
        /* Исходный массив */
        orig = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            orig[j] = rand() % 1000;
        }

        /* Shell Sort с шагами Кнута */
        generate_knuth_steps(n, steps_knuth, &step_count_knuth);
        arr_shell_knuth = (int*)malloc(n * sizeof(int));
        memcpy(arr_shell_knuth, orig, n * sizeof(int));
        shell_sort(arr_shell_knuth, n, steps_knuth, step_count_knuth, &shell_m, &shell_c);
        if (!is_sorted(arr_shell_knuth, n)) printf("Ошибка: ShellSort (Knuth) не отсортировала массив (n=%d)\n", n);
        free(arr_shell_knuth);

        /* Shell Sort с другой последовательностью (деление пополам) */
        generate_other_steps(n, steps_other, &step_count_other);
        arr_shell_other = (int*)malloc(n * sizeof(int));
        memcpy(arr_shell_other, orig, n * sizeof(int));
        shell_sort(arr_shell_other, n, steps_other, step_count_other, &shell_other_m, &shell_other_c);
        if (!is_sorted(arr_shell_other, n)) printf("Ошибка: ShellSort (другая) не отсортировала массив (n=%d)\n", n);
        free(arr_shell_other);

        steps_to_string(steps_knuth, step_count_knuth, knuth_str, sizeof(knuth_str));
        steps_to_string(steps_other, step_count_other, other_str, sizeof(other_str));

        printf("| %3d | %-24s | %14lld | %-24s | %14lld |\n",
               n, knuth_str, shell_m + shell_c, other_str, shell_other_m + shell_other_c);

        free(orig);
    }
    printf("+-----+--------------------------+----------------+--------------------------+----------------+\n");

    return 0;
}