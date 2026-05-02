#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned long long Mf = 0;
unsigned long long Cf = 0;

void reset_counters() {
    Mf = 0;
    Cf = 0;
}

void build_pyramid(int *a, int L, int R) {
    int x = a[L];
    Mf++;
    int i = L;
    
    while (1) {
        int j = 2 * i;
        if (j > R) break;
        if (j < R) {
            Cf++;
            if (a[j] < a[j+1]) {
                j = j + 1;
            }
        }
        Cf++;
        if (x >= a[j]) break;
        a[i] = a[j];
        Mf++;
        i = j;
    }
    a[i] = x;
    Mf++;
}

void build_heap(int *a, int n) {
    for (int i = n / 2; i >= 1; i--) {
        build_pyramid(a, i, n);
    }
}

void heap_sort(int *a, int n) {
    for (int i = n / 2; i >= 1; i--) {
        build_pyramid(a, i, n);
    }
    
    for (int i = n; i > 1; i--) {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        Mf += 3;
        
        build_pyramid(a, 1, i - 1);
    }
}

void generate_ascending(int *arr, int n) {
    for (int i = 1; i <= n; i++)
        arr[i] = i;
}

void generate_descending(int *arr, int n) {
    for (int i = 1; i <= n; i++)
        arr[i] = n - i + 1;
}

void generate_random(int *arr, int n) {
    for (int i = 1; i <= n; i++)
        arr[i] = rand() % 100;
}

int theoretical_pyramid_C(int L, int R) {
    if (L >= R) return 0;
    return (int)(2 * log2((double)R / L));
}

int theoretical_pyramid_M(int L, int R) {
    if (L >= R) return 0;
    return (int)(log2((double)R / L)) + 2;
}

int main() {
    srand(time(NULL));
    int sizes[] = {100, 200, 300, 400, 500};
    int num_sizes = 5;

    printf("=== Таблица 1: Трудоемкость построения пирамиды (Задание 2) ===\n");
    printf("%-5s | %-15s | %-10s | %-10s | %-10s\n", "N", "M+C теорет.", "Убыв.", "Случ.", "Возр.");
    printf("------------------------------------------------------------------\n");
    
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc((n + 1) * sizeof(int));
        
        int total_theor = 0;
        for (int L = n / 2; L >= 1; L--) {
            total_theor += theoretical_pyramid_C(L, n) + theoretical_pyramid_M(L, n);
        }

        generate_descending(arr, n);
        reset_counters();
        build_heap(arr, n);
        unsigned long long desc_total = Mf + Cf;

        generate_random(arr, n);
        reset_counters();
        build_heap(arr, n);
        unsigned long long rand_total = Mf + Cf;

        generate_ascending(arr, n);
        reset_counters();
        build_heap(arr, n);
        unsigned long long asc_total = Mf + Cf;

        printf("%-5d | %-15d | %-10llu | %-10llu | %-10llu\n", 
               n, total_theor, desc_total, rand_total, asc_total);
               
        free(arr);
    }

    printf("\n=== Таблица 2: Трудоемкость пирамидальной сортировки (Задание 4) ===\n");
    printf("%-5s | %-32s\n", "N", "HeapSort (Mф+Cф)");
    printf("%-5s | %-10s | %-10s | %-10s\n", "", "Убыв.", "Возр.", "Случ.");
    printf("----------------------------------------------------\n");
    
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc((n + 1) * sizeof(int));

        generate_descending(arr, n); // для убывающего массива
        reset_counters();
        heap_sort(arr, n);
        unsigned long long desc_total = Mf + Cf;

        generate_ascending(arr, n); // для возрастающего массива
        reset_counters();
        heap_sort(arr, n);
        unsigned long long asc_total = Mf + Cf;

        generate_random(arr, n); // для случайного массива
        reset_counters();
        heap_sort(arr, n);
        unsigned long long rand_total = Mf + Cf;

        printf("%-5d | %-10llu | %-10llu | %-10llu\n", 
               n, desc_total, asc_total, rand_total);
               
        free(arr);
    }

}