#include <stdio.h>

int main() {
    // Заданные числа
    int a = 15;
    int b = 4;
    
    // Вычисления
    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;
    float division = (float)a / b;
    
    // Вывод результатов
    printf("Числа: %d и %d\n\n", a, b);
    
    printf("Сложение:       %d + %d = %d\n", a, b, sum);
    printf("Вычитание:      %d - %d = %d\n", a, b, difference);
    printf("Умножение:      %d * %d = %d\n", a, b, product);
    printf("Целое деление:  %d / %d = %d\n", a, b, quotient);
    printf("Остаток:        %d %% %d = %d\n", a, b, remainder);
    printf("Вещественное:   %d / %d = %.2f\n", a, b, division);
    
    return 0;
}