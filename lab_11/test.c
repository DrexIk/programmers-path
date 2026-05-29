#include <stdlib.h>
#include <stdio.h>
int main() {
    int num = 42;
    printf("%d\n", num);
    int *p = &num;
    *p = 100;

    printf("%p\n", p);
    printf("%d\n", *p);

    return 0;
}