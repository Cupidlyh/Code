#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row=matrixRowSize-1,col=0;//��¼���½ǵ��к���
    while(row>=0&&col<matrixColSize){
        if(matrix[row][col]>target)//��������ֵ
            row--;//�м�1
        else
            if(matrix[row][col]<target)//С������ֵ
                col++;//�м�1
        else
            return true;
    }
    return false;
}
