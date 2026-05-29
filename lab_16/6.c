#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *sort(void *arg) {
    int *p = arg;
    int num = *p;
    sleep(num);
    printf("%d\n", num);
}

int main() {
    int arr[10] = {12, 9, 6, 6, 8, 3, 13, 45, 67, 2};
    pthread_t tids[10];

    for (int i = 0; i < 10; i++) {
        pthread_create(&tids[i], NULL, sort, &arr[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(tids[i], NULL);
    }
    
}
