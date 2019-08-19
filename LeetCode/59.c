#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **arr=(int **)malloc(sizeof(int *)*n);//����n��
    int *col=(int *)malloc(sizeof(int)*n);
    int i,j,k=1;
    for(i=0; i<n; i++){
        arr[i]=(int*)malloc(sizeof(int)*n);//ÿһ�п���n��
        col[i]=n;
        for(j=0;j<n;j++){
            arr[i][j]=0;//����ĳ�ʼ��
        }
    }
    int up=-1,down=n,left=-1,right=n;//�������ұ߽�
    i=0;
    j=0;
    while(k<=n*n){
        while(j<right&&k<=n*n)//����
            arr[i][j++]=k++;
        j--;//��һ����j���Լӻ�Խ�磬���Լ�һ
        i++;//��ֹ�ڹսǴ���洢һ��Ԫ��
        up++;//������������һ�У������ϱ߽�
        while(i<down&&k<=n*n)//����
            arr[i++][j]=k++;
        i--;//��һ����i���Լӻ�Խ�磬���Լ�һ
        j--;//��ֹ�ڹսǴ���洢һ��Ԫ��
        right--;//������������һ�У������ұ߽�
        while(j>left&&k<=n*n)//����
            arr[i][j--]=k++;
        j++;//��һ����j���Լ���Խ�磬���Լ�һ
        i--;//��ֹ�ڹսǴ���洢һ��Ԫ��
        down--;//������������һ�У������±߽�
        while(i>up&&k<=n*n)//����
            arr[i--][j]=k++;
        i++;//��һ����i���Լ���Խ�磬���Լ�һ
        j++;//��ֹ�ڹսǴ���洢һ��Ԫ��
        left++;//������������һ�У�������߽�
    }
    *returnSize=n;
    *returnColumnSizes=col;
    return arr;
}

