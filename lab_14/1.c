// Вариант 4 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct room {
        char name[50]; 
        int level; 
        int number; 
        int resolution;
    };

struct node {
    struct room data;
    struct node *next;
};

typedef struct node node_t;


node_t *newNode(struct room my_room) {

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = my_room;
    new_node->next = NULL;

    return new_node; // указ на нов уз
}   

void printList(node_t *head) {
    node_t* cur = head;
    while (cur) {
        printf("комната: %s\n уровень: %d\n номер: %d\n размер: %d\n",
            cur->data.name,
            cur->data.level,
            cur->data.number,
            cur->data.resolution
        );
        cur = cur->next;
    }
    printf("NULL\n");
}

node_t* appendBack(node_t* head, struct room data)
{
    node_t* new_node = newNode(data);

    if (head == NULL) {
        return new_node;
    }
    
    node_t* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;

    return head;
}

int main() {
    node_t  *head = NULL;
    int n;
    printf("Введите количество комнат:");
    scanf("%d", &n);

    srand(time(NULL));

    char rooms[5][50] = {
        "Зал",
        "Спальня",
        "Ванная",
        "Кухня",
        "Коридор"
    };

for (int i = 1; i <= n; i++) {
        struct room my_room;
        
        int rand_room = rand() % 5;
        int j = 0;
        while (rooms[rand_room][j] != '\0') {
            my_room.name[j] = rooms[rand_room][j];
            j++;
        }

        my_room.level = rand() % 10 + 1;
        my_room.number = i;
        my_room.resolution = rand() % 100 + 1;
        
        head = appendBack(head, my_room);
    }

    printList(head);
    
    return 0;
}