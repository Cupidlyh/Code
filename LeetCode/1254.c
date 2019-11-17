#include <stdio.h>
#include <stdlib.h>

int book[105][105],row,col;//book�Ǳ������
int move[4][2] = {-1,0,1,0,0,-1,0,1};//��һ�����߷����������ң�

void dfs(int p,int q,int **grid){//�����������
    int np,nq,k;
    for(k = 0; k < 4; k++){//forѭ����Ӧ����һ�������λ��
        np = p + move[k][0];
        nq = q + move[k][1];
        if(np < 0 || nq < 0 || np >= row || nq >= col)//�Ƿ�Խ��
            continue;
        if(grid[np][nq] == 0 && book[np][nq] == 0) {//�����һ����λ����½����û�����
            book[np][nq] = 1;//��Ǵ�λ��
            dfs(np,nq,grid);//�ݹ������������
        }
    }
}

int closedIsland(int** grid, int gridSize, int* gridColSize){
    memset(book,0,sizeof(book));//��������ʼ����Ϊ0
    row = gridSize;//��¼grid���������
    col = *gridColSize;//��¼grid���������
    int i,j;
    //��������forѭ���������ǽ������������ĸ��ߵ�½�ؽ��б�ǣ������Ϸ�յ����������
    for(i = 0; i < gridSize; i++) {
        if(grid[i][0] == 0 && book[i][0] == 0) {//��½����û�����
            book[i][0] = 1;//��Ǵ�λ��
            dfs(i,0,grid);//�����������
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

    int num = 0;//num��¼��յ��������
    for(i = 1; i < gridSize - 1; i++) {//����ȥ���ĸ��ߵ�grid����
        for(j = 1; j < *gridColSize - 1; j++) {
            if(grid[i][j] == 0 && book[i][j] == 0) {//��½����û�����
                num++;//����������1
                book[i][j] = 1;//��Ǵ�λ��
                dfs(i,j,grid);//�����������
            }
        }
    }
    return num;
}
