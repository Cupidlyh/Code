#include <iostream>
#include<algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int book[15][15];
int coor[8][2] = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int n,m,x,y;
int res;

//深度优先搜索
void dfs(int r,int c,int step)
{
    if (step == n * m - 1)
    {
        res++;
        return ;
    }
    for (int i = 0; i < 8; i++)
    {
        int xx = r + coor[i][0];
        int yy = c + coor[i][1];
        if (xx < 0 || yy < 0 || xx >=n || yy >= m)
            continue;
        if (book[xx][yy])
            continue;
        book[xx][yy] = 1;
        dfs(xx,yy,step + 1);
        book[xx][yy] = 0;
    }
    return ;
}

int main()
{
    int T;
    while (scanf("%d",&T) != EOF)
    {
        while (T--)
        {
            scanf("%d %d %d %d",&n,&m,&x,&y);
            memset(book,0,sizeof(book));
            res = 0;
            book[x][y] = 1;
            dfs(x,y,0);
            printf("%d\n",res);
        }
    }
    return 0;
}
