#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int flag,p,q;//flag标记是否找到一个路径走完整个棋盘
int dir[8][2]= {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};//可走的地方也是按照字典序排好的
int vis[30][30],xx[30],yy[30];//vis是标记数组，xx和yy存储结果

void dfs(int x,int y,int num)
{
    xx[num] = x;
    yy[num] = y;
    if(p * q == num)//走完整个棋盘
    {
        flag = 1;
        return ;
    }
    int nx,ny,i;
    for(i = 0; i < 8; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if(nx < 1 || ny < 1 || nx > p || ny > q)
            continue;
        if(!flag && !vis[nx][ny])
        {
            vis[nx][ny] = 1;
            dfs(nx,ny,num + 1);
            vis[nx][ny] = 0;
        }
    }
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        flag = 0;
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&p,&q);//p行q列
        vis[1][1] = 1;
        dfs(1,1,1);//从左上角开始深搜保证第一个结果一定是字典序
        printf("Scenario #%d:\n",i);
        if(flag)
        {
            for(j = 1; j <= p * q; j++)
            {
                printf("%c%d",yy[j] + 'A' - 1,xx[j]);//行是数字，列是字母
            }
            printf("\n\n");
        }
        else
            printf("impossible\n\n");
    }
    return 0;
}
