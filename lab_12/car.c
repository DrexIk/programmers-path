#include "car.h"

void bubbleSort(struct Car cars[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cars[j].price > cars[j + 1].price) {
                struct Car temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}

void generateCars(struct Car cars[], int count) {
    char *brands[] = {"BMW", "Mercedes", "Audi", "Toyota"};
    int num_brands = sizeof(brands) / sizeof(brands[0]);

    for (int i = 0; i < count; i++) {  
        int random_index = rand() % num_brands;
        snprintf(cars[i].brand, sizeof(cars[i].brand), "%s", brands[random_index]);

        cars[i].power = rand() % 300 + 150;
        cars[i].relis = rand() % 36 + 1990;
        cars[i].price = (rand() % 10000) + 10000;
    }
}

void printCars(struct Car cars[], int count) {    
    for (int i = 0; i < count; i++) { 
        printf("Марка: %s\n", cars[i].brand);
        printf("релиз: %d год\n", cars[i].relis);
        printf("мощность: %d л.с\n", cars[i].power);
        printf("цена: %.2f $\n\n", cars[i].price);
    }
}