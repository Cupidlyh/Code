#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0||* matrixColSize==0){//����Ϊ��ʱ
        * returnSize=0;
        int *arr=(int *)malloc(2*sizeof(int));
        return arr;
    }
    int *arr=(int *)malloc((matrixSize*(* matrixColSize)+1)*sizeof(int)),i=0,j=0,k=0;
    memset(arr,0,sizeof(arr));//һά����ĳ�ʼ��
    int up=-1,down=matrixSize,left=-1,right=* matrixColSize;//�����������ҵı߽�
    while(k<matrixSize*(* matrixColSize)){
        while(j<right&&k<matrixSize*(* matrixColSize))//����
            arr[k++]=matrix[i][j++];
        j--;//��һ����j���Լӻ�Խ�磬���Լ�һ
        i++;//��ֹ�ڹսǴ���Ԫ�ض�洢һ��
        up++;//������������һ�У������ϱ߽�
        while(i<down&&k<matrixSize*(* matrixColSize))//����
            arr[k++]=matrix[i++][j];
        i--;//��һ����i���Լӻ�Խ�磬���Լ�һ
        j--;//��ֹ�ڹսǴ���Ԫ�ض�洢һ��
        right--;//������������һ�У������ұ߽�
        while(j>left&&k<matrixSize*(* matrixColSize))//����
            arr[k++]=matrix[i][j--];
        j++;//��һ����j���Լ���Խ�磬���Լ�һ
        i--;//��ֹ�ڹսǴ���Ԫ�ض�洢һ��
        down--;//������������һ�У������±߽�
        while(i>up&&k<matrixSize*(* matrixColSize))//����
            arr[k++]=matrix[i--][j];
        i++;//��һ����i���Լ���Խ�磬���Լ�һ
        j++;//��ֹ�ڹսǴ���Ԫ�ض�洢һ��
        left++;//������������һ�У�������߽�
    }
    *returnSize=matrixSize*(* matrixColSize);
    return arr;
}
