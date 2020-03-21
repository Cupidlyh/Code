#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 2600);
    int num = 0;
    int i,j,k,flag,col,min;
    for(i = 0; i < matrixSize; i++) {
        min = 1000000;
        for(j = 0; j < * matrixColSize; j++) {
            if(matrix[i][j] < min) {//先找出每一行的最小值
                min = matrix[i][j];
                col = j;//记录当前行最小值所在的列
            }
        }
        flag = 0;
        for(k = 0; k < matrixSize; k++) {//在当前行最小值那一列判断此值是不是最大值
            if(matrix[k][col] > matrix[i][col]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {//幸运数存储
            res[num++] = matrix[i][col];
        }
    }
    *returnSize = num;
    return res;
}
