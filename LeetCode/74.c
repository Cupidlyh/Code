#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i,j,flag=0;
    if(matrixSize==0||* matrixColSize==0)//����Ϊ��ʱ
        return false;
    for(i=0;i<matrixSize;i++)//��һ���ҳ�Ԫ�����ڵ���
        if(target<=matrix[i][* matrixColSize-1]){
            flag=1;
            break;
        }
    if(flag==0)//�����������ѭ����˵������Ԫ�ش�������������Ԫ��
        return false;
    for(j=* matrixColSize-1;j>=0;j--)//��������
        if(matrix[i][j]==target)
            return true;
    return false;
}
