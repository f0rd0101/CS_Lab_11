#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int countValidElements(double** matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] > 0 && matrix[i][j] < 1)
                count++;
    return count;
}


double** createMatrix(int rows, int cols) {
    double** matrix = (double**) malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*) malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = ((double) rand() / RAND_MAX) * 2;  
        }
    }
    return matrix;
}


void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

int main() {
    srand(time(NULL));  

    int countTotal = 0;

 
    double** x = createMatrix(10, 15);
    double** y = createMatrix(20, 12);

    countTotal += countValidElements(x, 10, 15);
    countTotal += countValidElements(y, 20, 12);

    printf("Кількість елементів, що задовольняють умову: %d\n", countTotal);
    freeMatrix(x, 10);
    freeMatrix(y, 20);

    return 0;
}
