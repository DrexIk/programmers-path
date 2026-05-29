//29. Поменять в матрице правый верхний и левый нижний
//треугольники матрицы. Определить, сколько значений полученной
//матрицы совпадает с соответствующем значением исходной
//матрицы и вычислить минимальный положительный элемент в
//главной диагонали.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Введите размер матрицы NxN: ");
    scanf("%d", &n);

    int matrix[n][n];
	int new_matrix[n][n];
x    
    printf("Введите элементы матрицы %dx%d:\n", n, n);
    for(int i = 0; i < n; i++) {  
        for(int j = 0; j < n; j++) { 
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);  
        }
    }


    printf("Исходная матрица:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

// меняю местами правй верхний с левым нижним треугольником матрицы 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            new_matrix[i][j] = matrix[j][i];
    }
}


    // Выводим новую матрицу 
    printf("Новая матрица:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\n", new_matrix[i][j]);
        }
        printf("\n");
}

    return 0; 
}
