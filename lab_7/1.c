#include <stdio.h>
#include <string.h>


int main() {
    char string[1000];
    printf("Введите строку:");
    fgets(string, sizeof(string), stdin);
int sum = 0;
int chek = 0;
for (int i = 0; i < strlen(string); i++) {
    if (string[i] >= '0' && string[i] <= '9') { // 0 - 48  9 - 57 
        chek = 1;
        sum += string[i] - '0';
    } 
}


if (chek == 1) {
    printf("Сумма цифр: %d\n", sum);
}

else {
    printf("В тексте нет цифр\n");
}

}