#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

struct Car {
    char brand[50];
    int  relis;
    int power;
    float price;
};

void bubbleSort(struct Car cars[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cars[i].price > cars[j + 1].price) {
                struct Car temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}


int main() {
    srand(time(NULL));

void generateCars(struct Car cars[], int size) {
    char *brands[] = {"BMW", "Mercedes", "Audi", "Toyota"};
    int num_brands = sizeof(brands) / sizeof(brands[0]); // для опеределения размера массива

    struct Car cars[N];

    for (int i = 0; i < N; i++) {
        int random_index = rand() % num_brands;
        snprintf(cars[i].brand, sizeof(cars[i].brand), "%s", brands[random_index]);

        cars[i].power = rand() % 300 + 150;
        cars[i].relis = rand() % 36 + 1990;
        cars[i].price = rand() % 10000 + 10000;
    }
}

void printCars(struct Car cars[], int size, char* title) {
    for (int i = 0; i < N; i++) {
        printf("Марка: %s\nрелиз: %d год\nмощность: %d л.с\nцена: %.2f $\n\n",
        cars[i].brand, cars[i].relis, cars[i].power, cars[i].price);
    }
}

    printf("==========ОТСОРТИРОВАННЫЕ ДАННЫЕ ПО ЦЕНЕ АВТО==========\n\n");

    bubbleSort(cars, N);

    for (int i = 0; i < N; i++) {
    printf("Марка: %s\nрелиз: %d год\nмощность: %d л.с\nцена: %.2f $\n\n",
    cars[i].brand, cars[i].relis, cars[i].power, cars[i].price);
}
}
