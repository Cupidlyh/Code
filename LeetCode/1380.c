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
            if(matrix[i][j] < min) {//���ҳ�ÿһ�е���Сֵ
                min = matrix[i][j];
                col = j;//��¼��ǰ����Сֵ���ڵ���
            }
        }
        flag = 0;
        for(k = 0; k < matrixSize; k++) {//�ڵ�ǰ����Сֵ��һ���жϴ�ֵ�ǲ������ֵ
            if(matrix[k][col] > matrix[i][col]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {//�������洢
            res[num++] = matrix[i][col];
        }
    }
    *returnSize = num;
    return res;
}
