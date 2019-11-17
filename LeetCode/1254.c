#include <stdio.h>
#include <stdlib.h>

int book[105][105],row,col;//book是标记数组
int move[4][2] = {-1,0,1,0,0,-1,0,1};//下一步的走法（上下左右）

void dfs(int p,int q,int **grid){//深度优先搜索
    int np,nq,k;
    for(k = 0; k < 4; k++){//for循环对应的下一步到达的位置
        np = p + move[k][0];
        nq = q + move[k][1];
        if(np < 0 || nq < 0 || np >= row || nq >= col)//是否越界
            continue;
        if(grid[np][nq] == 0 && book[np][nq] == 0) {//如果下一步的位置是陆地且没被标记
            book[np][nq] = 1;//标记此位置
            dfs(np,nq,grid);//递归深度优先搜索
        }
    }
}

int closedIsland(int** grid, int gridSize, int* gridColSize){
    memset(book,0,sizeof(book));//标记数组初始化置为0
    row = gridSize;//记录grid数组的行数
    col = *gridColSize;//记录grid数组的列数
    int i,j;
    //下面两个for循环的作用是将连接起来到四个边的陆地进行标记（不符合封闭岛屿的条件）
    for(i = 0; i < gridSize; i++) {
        if(grid[i][0] == 0 && book[i][0] == 0) {//是陆地且没被标记
            book[i][0] = 1;//标记此位置
            dfs(i,0,grid);//深度优先搜索
        }
        if(grid[i][*gridColSize - 1] == 0 && book[i][*gridColSize - 1] == 0) {
            book[i][*gridColSize - 1] = 1;
            dfs(i,*gridColSize - 1,grid);
        }
    }
    for(j = 0; j < *gridColSize; j++) {
        if(grid[0][j] == 0 && book[0][j] == 0) {
            book[0][j] = 1;
            dfs(0,j,grid);
        }
        if(grid[gridSize - 1][j] == 0 && book[gridSize - 1][j] == 0) {
            book[gridSize - 1][j] = 1;
            dfs(gridSize - 1,j,grid);
        }
    }

    int num = 0;//num记录封闭岛屿的数量
    for(i = 1; i < gridSize - 1; i++) {//遍历去除四个边的grid数组
        for(j = 1; j < *gridColSize - 1; j++) {
            if(grid[i][j] == 0 && book[i][j] == 0) {//是陆地且没被标记
                num++;//岛屿数量加1
                book[i][j] = 1;//标记此位置
                dfs(i,j,grid);//深度优先搜索
            }
        }
    }
    return num;
}
