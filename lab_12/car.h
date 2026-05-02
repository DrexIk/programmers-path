#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define N 4

struct Car {
    char brand[50];
    int  relis;
    int power;
    float price;
};

void bubbleSort(struct Car cars[], int n);
void generateCars(struct Car cars[], int count);
void printCars(struct Car cars[], int count);     