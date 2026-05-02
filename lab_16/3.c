#include <pthread.h>
#include <stdio.h>

void *pthread_child(void *arg) {
    char *text = arg;

    for(int i = 1; i <= 5; ++i) {
        printf("%s дочерний поток %d\n", text, i);
    }
}

int main() {
    pthread_t pid[4];
    char *name[4] = {"поток 1", "поток 2", "поток 3", "поток 4"};
    for(int i = 0; i < 4; i++) {
        pthread_create(&pid[i], NULL, pthread_child, name[i]);
    }
    for(int i = 0; i < 4; i++) {
        pthread_join(pid[i], NULL);
    }
    for(int i = 1; i <= 5; ++i) {
        printf("родительский поток %d\n", i);
    }
}
