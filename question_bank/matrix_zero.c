/**
 * 矩阵置零
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 *
 * 示例:
 * 输入:
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * 输出:
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 */

#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>

void init(int ***matrix, int matrixSize, const int *matrixColSize);

void setZeroes(int **matrix, int matrixSize, const int *matrixColSize);

void printMatrix(int **matrix, int matrixSize, const int *matrixColSize);

int main() {
    int matrixSize = 5;
    int matrixColSize[] = {5};
    int **matrix;
    //初始化矩阵
    init(&matrix, matrixSize, matrixColSize);
    printf("置零前：\n");
    printMatrix(matrix, matrixSize, matrixColSize);
    //矩阵置零
    setZeroes(matrix, matrixSize, matrixColSize);

    printf("置零后：\n");
    printMatrix(matrix, matrixSize, matrixColSize);
    return 0;
}

void init(int ***matrix, int matrixSize, const int *matrixColSize) {
    *matrix = (int **) malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; ++i) {
        (*matrix)[i] = malloc(sizeof(int) * matrixColSize[0]);
    }
    //赋值
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            (*matrix)[i][j] = 1 + i + j;
        }
    }
    (*matrix)[3][0] = 0;
}

void setZeroes(int **matrix, int matrixSize, const int *matrixColSize) {
    bool isCol = false;
    int row = matrixSize;
    int column = matrixColSize[0];
    for (int i = 0; i < row; ++i) {
        if (matrix[i][0] == 0) {
            isCol = true;
        }
        for (int j = 1; j < column; ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < column; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int j = 0; j < column; ++j) {
            matrix[0][j] = 0;
        }
    }

    if (isCol == true) {
        for (int i = 0; i < row; ++i) {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(int **matrix, int matrixSize, const int *matrixColSize) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}