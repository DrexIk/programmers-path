//10. Посчитать сколько нулей в числе с третьего по 13 бит, включая эти биты
#include <stdio.h>
int main() {
    int count = 0;
    int number;
    printf("Введите число:");
    scanf("%d", &number);
    
    for (int i = 3; i <= 13; i++){
        if (((number >> i) & 1) == 0){
            count += 1;
        }
}
printf("%d\n", count);

}
/*
//11. Используя битовые операции проверить кратно ли число 16
#include <stdio.h>
int main() {
    int number;
    printf("Введите число:");
    scanf("%d", &number);

    if ((number & 15) == 0) {
        printf("Кратно 16\n");
    }
    else {
        printf("Не кратно 16\n");
    
    }
}
*/