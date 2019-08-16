#include <stdio.h>
#include <stdlib.h>

int book[5000][5000],n,m,a[5000][5000];//ȫ�ֱ���

void dfs(int x,int y,int color){//�����������
    int k,tx,ty;
    int next[4][2]={0,1,1,0,0,-1,-1,0};//�������飬�ֱ������ң��£�����
    a[x][y]=color;//Ⱦɫ
    for(k=0;k<=3;k++){
        tx=x+next[k][0];//��һ���ĺ�����
        ty=y+next[k][1];//��һ����������
        if(tx<0||tx>n||ty<0||ty>m)//�ж��Ƿ�Խ��
            continue;
        if(a[tx][ty]==1&&book[tx][ty]==0){//�ж��Ƿ���½��
            book[tx][ty]=1;//���������Ѿ��߹�
            dfs(tx,ty,color);//������һ����
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize==0)
        return 0;
    n=gridSize-1;//��¼���������
    m=*gridColSize-1;//��¼���������
    int i,j,num=0;
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++){
            if(grid[i][j]=='1')
                a[i][j]=1;//����a���ǽ�grid����ת�������ʹ洢
            else
                a[i][j]=0;
            book[i][j]=0;//�������ĳ�ʼ��
        }
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++){
            if(a[i][j]==1){//��ÿ��½�ؽ���Ⱦɫ�ж��������ĸ�С��
                num--;//С��Ⱦɫ�ı�ţ�ÿ��С����ͬ��ţ����Լ�1
                book[i][j]=1;
                dfs(i,j,num);
            }
        }
    return -num;//����С������
}
