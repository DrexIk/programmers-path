//Оценка 3: пользователь задает с клавиатуры некоторое N (от 1 до 3). Создать
//матрицу NxN. Вычислить для нее определитель и вывести на экран вместе с
//матрицей.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
printf("\n");

    if (n == 1) {
        printf("%d", matrix[0][0]);
    }
    else if (n == 2) {
        int opred = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        printf("%d\n", opred);
    }
    else {
        int opred = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]);
        printf("%d\n", opred);
    }
    




    
}
    