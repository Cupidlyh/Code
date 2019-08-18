#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i,j,flag=0;
    if(matrixSize==0||* matrixColSize==0)//数组为空时
        return false;
    for(i=0;i<matrixSize;i++)//这一步找出元素所在的行
        if(target<=matrix[i][* matrixColSize-1]){
            flag=1;
            break;
        }
    if(flag==0)//如果不是跳出循环，说明所给元素大于数组中最大的元素
        return false;
    for(j=* matrixColSize-1;j>=0;j--)//遍历此行
        if(matrix[i][j]==target)
            return true;
    return false;
}
