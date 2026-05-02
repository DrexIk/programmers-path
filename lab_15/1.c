#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dats{
    char name[50];
    int number;
    char level[50];
};

int main(int argc, char *argv[]) { // argc - количество аргументов // argv[] - массив строк с аргументами
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);

    }
    FILE *file = NULL; // указатель на структуру типа FILE.
    file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(1);
        }

    char buffer[256];
    struct dats people[10];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *name = strtok(buffer, ";\n");
        char *number = strtok(NULL, ";\n");
        char *level = strtok(NULL, ";\n");
        if (name != NULL && number != NULL && level != NULL) {
        // Заносим данные в структуру
        strcpy(people[count].name, name);           // копируем имя
        people[count].number = atoi(number);        // преобразуем и сохраняем число
        strcpy(people[count].level, level);         // копируем уровень
        count++;                                    
    }
    }   
    fclose(file);
    printf("---------------------------------\n");
    printf("    Name    |   Number  | Level|\n");
    printf("---------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %s | %d | %s |\n", people[i].name, people[i].number, people[i].level);
        printf("---------------------------------\n");
    }
}
