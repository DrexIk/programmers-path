#include <stdio.h>
#include <string.h>

// Проблема: number.num != 1025?

typedef struct {
    char str[12]; // изменил с 4 на 12. проблема была в том что буфер переполнялся из-за того что в типе данных инт 4 байта и после комп добавляется \0
    int num;
} NumberRepr;

void format(NumberRepr* number) {
    sprintf(number->str, "%3d", number->num);
}

int main() {
    NumberRepr number = { .num = 1025 };
    format(&number);
    printf("str: %s\n", number.str);
    printf("num: %d\n", number.num);
    return 0;
}