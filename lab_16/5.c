#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void kill_msg(void *arg){
    char *text = arg;
    printf("поток %s завершился\n", text);
}     

void *pthread_child(void *arg) {
    char *text = arg;
    pthread_cleanup_push(kill_msg, text);
    for(int i = 1; i <= 5; ++i) {
        sleep(1);
        printf("%s дочерний поток %d\n", text, i);
    }
    pthread_cleanup_pop(0);
}

int main() {
    pthread_t pid[4];
    char *name[4] = {"поток 1", "поток 2", "поток 3", "поток 4"};
    for(int i = 0; i < 4; i++) {
        pthread_create(&pid[i], NULL, pthread_child, name[i]);
    }

    sleep(2);
    for(int i = 0; i < 4; i++) {
        pthread_cancel(pid[i]);
    }

    for(int i = 0; i < 4; i++) {
        pthread_join(pid[i], NULL);
    }
    for(int i = 1; i <= 5; ++i) {
        sleep(1);
        printf("родительский поток %d\n", i);
    }
}
