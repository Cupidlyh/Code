#include <stdio.h>
#include <stdlib.h>

int countNegatives(int** grid, int gridSize, int* gridColSize){
    int num = 0,i,j;
    for(i = 0; i < gridSize; i++)//���������Ҹ����ĸ���
        for(j = 0; j < *gridColSize; j++)
            if(grid[i][j] < 0)
                num++;
    return num;
}


