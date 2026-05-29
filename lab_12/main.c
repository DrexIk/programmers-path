#include "car.h"

void time_sort(int size) {
    struct Car *testCars = malloc(size * sizeof(struct Car));
    
    generateCars(testCars, size);
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    bubbleSort(testCars, size);
    gettimeofday(&end, NULL);
    
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6; /// 1 / 1000000
    
    printf("N = %d, Время: %.6f сек\n", size, elapsed);
    
    free(testCars);
}

int main() {
    srand(time(NULL));
    
    time_sort(100);
    time_sort(10000);
    time_sort(100000);
    printf("\n");
    
    struct Car cars[N];
    
    generateCars(cars, N);
    printf("Исходные автомобили:\n");
    printCars(cars, N); 
    
    bubbleSort(cars, N);
    printf("\nОТСОРТИРОВАННЫЕ ПО ЦЕНЕ:\n");
    printCars(cars, N);      
    
    return 0;
}