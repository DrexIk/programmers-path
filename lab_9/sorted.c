// Функция сортировки пузырьком

/* Сортировка пузырьком (bubble sort) в языке Си — это простой алгоритм сортировки,
который основан на многократном проходе по сортируемому массиву.
*/

#include <stdio.h>

#define N 5

void bubble_sort(int size, int arr[size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // если текущий > следующего, то делаем swap - меняем местами
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void print_array(int size, int array[size]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {

    int a[] = {2, 0};
    int size = sizeof(a) / sizeof(a[0]);
    
    printf("Исходный массив: ");
    print_array(size, a);

    bubble_sort(size, a);

    printf("Отсортированный массив: ");
    print_array(size, a);

    return 0;
}
