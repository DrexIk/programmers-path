#include <stdio.h>
#include <stdlib.h>

// Скомпилируй и запусти меня

void init(int **arr, int *n) { // * в main переменная arr = 0x0
    *arr = malloc(*n * sizeof(int)); // * на arr для записи адреса с malloc в main
    for (long i = 0; i < *n; ++i) { 
        (*arr)[i] = i; // * для получения адреса из arr. используем () тк у [] скобок приоритет выше чем у указателя
    }
    *n = 5;
}

int main() {
    int *arr = NULL;
    int n = 10;

    init(&arr, &n); // используем & для передачи адреса указатедъля
    // n = ? 

    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}