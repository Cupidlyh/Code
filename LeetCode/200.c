#include <stdio.h>
#include <stdlib.h>

int book[5000][5000],n,m,a[5000][5000];//全局变量

void dfs(int x,int y,int color){//深度优先搜索
    int k,tx,ty;
    int next[4][2]={0,1,1,0,0,-1,-1,0};//方向数组，分别是向右，下，左，上
    a[x][y]=color;//染色
    for(k=0;k<=3;k++){
        tx=x+next[k][0];//下一步的横坐标
        ty=y+next[k][1];//下一步的纵坐标
        if(tx<0||tx>n||ty<0||ty>m)//判断是否越界
            continue;
        if(a[tx][ty]==1&&book[tx][ty]==0){//判断是否是陆地
            book[tx][ty]=1;//标记这个点已经走过
            dfs(tx,ty,color);//尝试下一个点
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize==0)
        return 0;
    n=gridSize-1;//记录数组的行数
    m=*gridColSize-1;//记录数组的列数
    int i,j,num=0;
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++){
            if(grid[i][j]=='1')
                a[i][j]=1;//数组a就是将grid数组转换成整型存储
            else
                a[i][j]=0;
            book[i][j]=0;//标记数组的初始化
        }
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++){
            if(a[i][j]==1){//对每个陆地进行染色判断它属于哪个小岛
                num--;//小岛染色的编号，每个小岛不同编号，所以减1
                book[i][j]=1;
                dfs(i,j,num);
            }
        }
    return -num;//返回小岛数量
}
