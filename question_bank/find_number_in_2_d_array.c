/**
 * 二维数组中的查找
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *
 * 示例:
 * 现有矩阵 matrix 如下：
 *
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 *
 * 给定 target = 5，返回 true。
 *
 * 给定 target = 20，返回 false。
 *
 * 限制：
 *
 * 0 <= n <= 1000
 *
 * 0 <= m <= 1000
 */
#include <stdio.h>
#include <stdbool.h>

bool findNumberIn2DArray(int **matrix, int matrixSize, int *matrixColSize, int target);

bool findNumberIn2DArray_1(int **matrix, int matrixSize, int *matrixColSize, int target);

int main() {
    int row = 5;
    int col = 5;
    int matrix[5][5] = {{1,  4,  7,  11, 15},
                        {2,  5,  8,  12, 19},
                        {3,  6,  9,  16, 22},
                        {10, 13, 14, 17, 24},
                        {18, 21, 23, 26, 30}};
    bool result = findNumberIn2DArray((int **) matrix, row, &col, 5);
    printf("输出结果：%d\n", result);
    return 0;
}

bool findNumberIn2DArray(int **matrix, int matrixSize, int *matrixColSize, int target) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }
    int row = 0, col = *matrixColSize - 1;
    for (; row < matrixSize && col >= 0;) {
        int num = *((int *) matrix + row * (*matrixColSize) + col);
        //int num = matrix[row][col];
        if (num == target) {
            return true;
        } else if (num > target) {
            col--;
        } else {
            row++;
        }
    }
    return false;
}

bool findNumberIn2DArray_1(int **matrix, int matrixSize, int *matrixColSize, int target) {
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < *matrixColSize; ++j) {
            int num = *((int *) matrix + i * (*matrixColSize) + j);
            if (num == target) {
                return true;
            }
        }
    }
    return false;
}
