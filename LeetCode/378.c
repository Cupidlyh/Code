#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){//�Ƚ���
    return *(int *)a-*(int *)b;//��С��������
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int arr[500000]={0},i,j,m=0;
    for(i=0;i<matrixSize;i++)//���������Ķ�ά������һά����arr��
        for(j=0;j<*matrixColSize;j++)
            arr[m++]=matrix[i][j];
    qsort(arr,m,sizeof(arr[0]),cmp);//������
    return arr[k-1];
}
