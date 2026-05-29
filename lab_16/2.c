#include <pthread.h>
#include <stdio.h>

void *pthread_child(void *arg) {
    for(int i = 1; i <= 5; ++i) {
        printf("дочерний поток %d\n", i);
    }
}

int main() {
    pthread_t pid;
    pthread_create(&pid, NULL, pthread_child, NULL);
    pthread_join(pid, NULL); // перенесли объединени потоков 
    for(int i = 1; i <= 5; ++i) {
        printf("родительский поток %d\n", i);
    }
    pthread_join(pid, NULL);
}