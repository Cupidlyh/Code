#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row=matrixRowSize-1,col=0;//记录左下角的行和列
    while(row>=0&&col<matrixColSize){
        if(matrix[row][col]>target)//大于所给值
            row--;//行减1
        else
            if(matrix[row][col]<target)//小于所给值
                col++;//列加1
        else
            return true;
    }
    return false;
}
