#include <stdio.h>
int main() {
    int mx = -1000000;
    short int counter = 0; 
    short int complex[6] = {1000, -5, 100000, 6, 5674, -11};
    double signal_energy =  0;
    for (int i = 0; i < 6; i += 2) {
        if (complex[i] > mx) { // ищем макс значение 
            mx = complex[i];
        }
        printf("complex[%d] = %d + j*(%d)\n\n", counter, complex[i], complex[i + 1]);

        signal_energy += complex[i] * complex[i] + complex[i + 1] * complex[i + 1];
        counter += 1;
    }
    printf("Энергия сигнала для complex: %f\n", signal_energy);
    printf("Максимальный элемент среди реальной части: %d\n", mx);
}



