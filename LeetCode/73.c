#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,flag=0;//flag用来标记第0列是否需要置为0
    for(i=0;i<matrixSize;i++){//遍历一遍数组
        for(j=0;j<*matrixColSize;j++){
            if(matrix[i][j]==0){//将出现0元素的那一行和那一列的首元素标记为0
                if(j==0)
                    flag=1;//如果是第0列需要标记就用flag来标记
                else
                    matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }
    for(i=1;i<matrixSize;i++){//先判断除去第0行以外行的首元素
        if(matrix[i][0]==0){//如果是零
            for(j=0;j<* matrixColSize;j++)//这一行全置为0
                matrix[i][j]=0;
        }
    }
    for(j=1;j<* matrixColSize;j++){//先判断除去第0列以外列的首元素
        if(matrix[0][j]==0){//如果是0
            for(i=0;i<matrixSize;i++)//这一列全置为0
                matrix[i][j]=0;
        }
    }
    if(matrix[0][0]==0)//判断第0行的首元素是否为0
        for(j=0;j<* matrixColSize;j++)
            matrix[0][j]=0;
    if(flag==1)//判断第0列的首元素是否被标记
        for(i=0;i<matrixSize;i++)
            matrix[i][0]=0;
}
