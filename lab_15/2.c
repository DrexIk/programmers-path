#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dats{
    char name[50];
    int number;
    char level[50];
};

void open_and_type(struct dats *people, int count);
void search_in_database_id();
void compress();
void decompress();

int main(int argc, char *argv[]) { // argc - количество аргументов (первый аргумент - имя программы) // argv[] - массив строк с аргументами
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);

    }
    FILE *file = NULL;
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

    open_and_type(people, count);
    search_in_database_id();

    compress();
    decompress();
}

// на 4
void open_and_type(struct dats *people, int count) {
    FILE *file_write = NULL;
        file_write = fopen("database.dat", "wb");
            if (file_write == NULL) {
                perror("Error opening file");
                exit(1);
            }
    fwrite(people, sizeof(struct dats), count, file_write);
    fclose(file_write);
}

void search_in_database_id() {
    FILE *file_read = NULL;
    file_read = fopen("database.dat", "rb");
    if (file_read == NULL) {
        printf("Error opening file (database.dat)");
        exit(1);
    }
    int id = 0;
    printf("Введите ID:");
    scanf("%d", &id);
    
    struct dats temp;
    int found = 0;
    while (fread(&temp, sizeof(struct dats), 1, file_read) == 1) { // fread возвращает количество успешно прочитанных элементов
        if (temp.number == id) {
            printf("| %s | %d | %s |\n", temp.name, temp.number, temp.level);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Сотрудник с ID %d не найден\n", id);
    }
}

// 5 

void compress() {
    FILE *input = NULL;
    input = fopen("database.dat", "rb");
        if (input == NULL) {
            perror("Error opening file");
            exit(1);
        }

    FILE *output = NULL;
    output = fopen("database.rle", "wb");
        if (output == NULL) {
            perror("Error creations file");
            exit(1);
        }
    
    // перемещение каретки 
    fseek(input, 0, SEEK_END);
    long original_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    char *buffer = (char*)malloc(original_size);
    size_t bytes_read = fread(buffer, 1, original_size, input);

    


    unsigned char current_byte = buffer[0];
    unsigned char count = 1;
    long compressed_size = 0;
    
    for (long i = 1; i < original_size; i++) {
        if (buffer[i] == current_byte && count < 255) {
            count++;  // Увеличиваем счетчик повторений
        } else {
            // Записываем пару [счетчик][значение]
            fwrite(&count, 1, 1, output);
            fwrite(&current_byte, 1, 1, output);
            compressed_size += 2;
            
            // Начинаем новую последовательность
            current_byte = buffer[i];
            count = 1;
        }
    }
    
    // Записываем последнюю последовательность
    fwrite(&count, 1, 1, output);
    fwrite(&current_byte, 1, 1, output);
    compressed_size += 2;
    
    // Получаем точный размер сжатого файла
    fflush(output);
    fseek(output, 0, SEEK_END);
    long actual_compressed_size = ftell(output);
    
    // Выводим отчет о сжатии
    double original_kb = original_size / 1024.0;
    double compressed_kb = actual_compressed_size / 1024.0;
    double compression_ratio = (1.0 - (double)actual_compressed_size / original_size) * 100.0;
    
    printf("\n========== ОТЧЕТ О СЖАТИИ ==========\n");
    printf("Размер до:   %.2f Кб (%ld байт)\n", original_kb, original_size);
    printf("Размер после: %.2f Кб (%ld байт)\n", compressed_kb, actual_compressed_size);
    printf("Сжатие:      %.2f%%\n", compression_ratio);
    printf("Экономия:    %.2f Кб\n", (original_size - actual_compressed_size) / 1024.0);
    printf("=====================================\n");
    
    // Очистка и закрытие
    free(buffer);
    fclose(input);
    fclose(output);
    
    printf("[+] Сжатие завершено. Результат в файле: database.rle\n");
}

void decompress() {
    printf("\n=== НАЧАЛО РАСПАКОВКИ RLE ===\n");
    
    // Открываем сжатый файл
    FILE *input = fopen("database.rle", "rb");
    if (input == NULL) {
        perror("Ошибка открытия database.rle");
        return;
    }
    
    // Открываем файл для восстановленных данных
    FILE *output = fopen("database_decompressed.dat", "wb");
    if (output == NULL) {
        perror("Ошибка создания database_decompressed.dat");
        fclose(input);
        return;
    }
    
    unsigned char count, value;
    long decompressed_size = 0;
    
    // Читаем пары [счетчик][значение] из сжатого файла
    while (fread(&count, 1, 1, input) == 1) {
        if (fread(&value, 1, 1, input) != 1) {
            printf("[!] Ошибка: файл поврежден\n");
            break;
        }
        
        // Восстанавливаем оригинальные данные
        for (int i = 0; i < count; i++) {
            fwrite(&value, 1, 1, output);
            decompressed_size++;
        }
    }
    
    printf("[*] Восстановлено %ld байт (%.2f Кб)\n", decompressed_size, decompressed_size/1024.0);
    
    // Проверяем соответствие с оригиналом
    FILE *original = fopen("database.dat", "rb");
    if (original != NULL) {
        fseek(original, 0, SEEK_END);
        long original_size = ftell(original);
        fclose(original);
        
        if (decompressed_size == original_size) {
            printf("[+] РАСПАКОВКА УСПЕШНА! Размер совпадает с оригиналом\n");
        } else {
            printf("[!] ВНИМАНИЕ: Размер не совпадает! Оригинал: %ld, Восстановлено: %ld\n", 
                   original_size, decompressed_size);
        }
    }
    
    fclose(input);
    fclose(output);
    printf("[+] Распаковка завершена. Результат в файле: database_decompressed.dat\n");
}
