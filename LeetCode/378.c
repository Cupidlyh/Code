#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){//比较器
    return *(int *)a-*(int *)b;//从小到大排序
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int arr[500000]={0},i,j,m=0;
    for(i=0;i<matrixSize;i++)//将传进来的二维数组存进一维数组arr中
        for(j=0;j<*matrixColSize;j++)
            arr[m++]=matrix[i][j];
    qsort(arr,m,sizeof(arr[0]),cmp);//排序函数
    return arr[k-1];
}
