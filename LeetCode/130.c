#include <stdio.h>
#include <stdlib.h>

int n,m;

void dfs(char **board,int row,int col) {//�����������
    board[row][col] = 'b';//����߽���ͨ�ı�ǳ�b��ĸ
    int k,tx,ty;
    int next[4][2]={0,1,1,0,0,-1,-1,0};//�������飬�ֱ������ң��£�����
    for(k=0;k<=3;k++){
        tx=row+next[k][0];//��һ���ĺ�����
        ty=col+next[k][1];//��һ����������
        if(tx<0||tx>n||ty<0||ty>m)//�ж��Ƿ�Խ��
            continue;
        if(board[tx][ty] == 'O'){
            dfs(board,tx,ty);//������һ����
        }
    }
    return ;
}

void solve(char** board, int boardSize, int* boardColSize){
    if(boardSize == 0)
        return ;
    int i,j;
    n = boardSize-1;//��¼���������
    m = *boardColSize-1;//��¼���������
    for(j=0;j<*boardColSize;j++) {//�ҳ����±߽��е�O���������ѣ���߽���ͨ��O�Ͳ��ܱ�X���
        if(board[0][j] == 'O')
            dfs(board,0,j);
        if(board[boardSize-1][j] == 'O')
            dfs(board,boardSize-1,j);
    }

    for(i=1;i<boardSize-1;i++) {//�ҳ����ұ߽��е�O����������
        if(board[i][0] == 'O')
            dfs(board,i,0);
        if(board[i][*boardColSize-1] == 'O')
            dfs(board,i,*boardColSize-1);
    }

    for(i=0;i<boardSize;i++)//�������������һ��
        for(j=0;j<*boardColSize;j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == 'b')
                board[i][j] = 'O';
        }
}
