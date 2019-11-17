#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes){
    int i,j,vis[100001] = {0},sum = upper,sum1 = 0,sum2 = 0;//visΪ�������
    int **res = (int **)malloc(sizeof(int *) * 2);//���ٶ�ά���鱣����
    for(i = 0; i < 2; i++) {
        res[i] = (int *)malloc(sizeof(int) * colsumSize);
        for(j = 0; j < colsumSize; j++)
            res[i][j] = 0;
    }
    int *col = (int *)malloc(sizeof(int) * 2);//��¼res����ÿһ��Ԫ�صĸ���
    col[0] = colsumSize;
    col[1] = colsumSize;
    *returnColumnSizes = col;
    *returnSize = 2;//res���������
    for(i = 0; i < colsumSize; i++) {//�ȱ���colsum����
        if(colsum[i] == 1)//�����Ϊ1
            res[0][i] = 1;//��0�е�i����1
        if(colsum[i] == 2) {//�����Ϊ2
            res[0][i] = 1;//��0�е�i����1
            res[1][i] = 1;//��1�е�i����1
            vis[i] = 1;//��Ǵ���
            sum--;//��0�е��ܺͼ�1
        }
    }
    for(i = 0; i < colsumSize; i++) {//��һ�����res����ĵ�0��
        if(sum == 0)//�ܺ�Ϊ0ʱ����ѭ��
            break;
        if(res[0][i] == 1 &&vis[i] == 0) {//�����0�е�i��Ϊ1��û�����
            sum--;////��0�е��ܺͼ�1
            vis[i] = 1;//��Ǵ���
        }
    }
    for(i = 0; i < colsumSize; i++) {//�ڶ������res����ĵ�0��
        if(vis[i] == 0 &&res[0][i] == 1) {//δ����ǵ��ҵ�0�е�i��Ϊ1��
            res[0][i] = 0;//��0�к͵�1�е����ֽ��н���
            res[1][i] = 1;
        }
    }
    for(i = 0; i < colsumSize; i++) {//��������res����
        if(res[1][i] == 1)
            sum2++;//sum2��¼��ά�����1�е��ܺ�
        if(res[0][i] == 1)
            sum1++;//sum1��¼��ά�����0�е��ܺ�
    }
    if(sum1 != upper || sum2 != lower) {
        *returnSize = 0;
    }
    return res;
}
