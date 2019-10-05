#include <stdio.h>
#include <stdlib.h>

int n,m;

void dfs(char **board,int row,int col) {//深度优先搜索
    board[row][col] = 'b';//将与边界连通的标记成b字母
    int k,tx,ty;
    int next[4][2]={0,1,1,0,0,-1,-1,0};//方向数组，分别是向右，下，左，上
    for(k=0;k<=3;k++){
        tx=row+next[k][0];//下一步的横坐标
        ty=col+next[k][1];//下一步的纵坐标
        if(tx<0||tx>n||ty<0||ty>m)//判断是否越界
            continue;
        if(board[tx][ty] == 'O'){
            dfs(board,tx,ty);//尝试下一个点
        }
    }
    return ;
}

void solve(char** board, int boardSize, int* boardColSize){
    if(boardSize == 0)
        return ;
    int i,j;
    n = boardSize-1;//记录数组的行数
    m = *boardColSize-1;//记录数组的列数
    for(j=0;j<*boardColSize;j++) {//找出上下边界中的O并进行深搜，与边界连通的O就不能被X填充
        if(board[0][j] == 'O')
            dfs(board,0,j);
        if(board[boardSize-1][j] == 'O')
            dfs(board,boardSize-1,j);
    }

    for(i=1;i<boardSize-1;i++) {//找出左右边界中的O并进行深搜
        if(board[i][0] == 'O')
            dfs(board,i,0);
        if(board[i][*boardColSize-1] == 'O')
            dfs(board,i,*boardColSize-1);
    }

    for(i=0;i<boardSize;i++)//将整个数组遍历一边
        for(j=0;j<*boardColSize;j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == 'b')
                board[i][j] = 'O';
        }
}
