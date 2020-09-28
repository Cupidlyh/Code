#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

struct node
{
    int x,y,s;
    node() {}
    node(int xx,int yy,int ss):x(xx),y(yy),s(ss) {}
};


char mapp[1005][1005];//存地图
int fireTime[1005][1005];//记录火蔓延到地图上的每个位置的最短时间
int book[1005][1005];//标记数组

int R,C;
int jx,jy;//J的坐标

//广度优先搜索J逃出去的最短时间
int J_dfs()
{
    int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
    memset(book,0,sizeof(book));
    queue<node> q;
    q.push(node(jx,jy,0));
    book[jx][jy] = 1;
    while (!q.empty())
    {
        int xx = q.front().x;
        int yy = q.front().y;
        int ss = q.front().s;
        q.pop();
        if (xx == 0 || yy == 0 || xx == R - 1 || yy == C - 1)
        {
            return ss + 1;
        }
        for (int i = 0; i < 4; i++)
        {
            int x1 = xx + coor[i][0];
            int y1 = yy + coor[i][1];
            if (x1 < 0 || y1 < 0 || x1 >= R || y1 >= C)
                continue;
            if (book[x1][y1] || mapp[x1][y1] == '#')
                continue;
            //J到达此位置时火不能到达此位置(-1代表的是火无法到达此位置)
            if (fireTime[x1][y1] != -1 && ss + 1 >= fireTime[x1][y1])
                continue;
            q.push(node(x1,y1,ss + 1));
            book[x1][y1] = 1;
        }
    }
    return -1;
}

//广度优先搜索计算出火蔓延到所有可走的点的最短时间
void F_dfs()
{
    memset(fireTime,-1,sizeof(fireTime));
    memset(book,0,sizeof(book));
    int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
    queue<node> q;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mapp[i][j] == 'F')
            {
                q.push(node(i,j,0));
                book[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int xx = q.front().x;
        int yy = q.front().y;
        int ss = q.front().s;
        fireTime[xx][yy] = ss;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = xx + coor[i][0];
            int y1 = yy + coor[i][1];
            if (x1 < 0 || y1 < 0 || x1 >= R || y1 >= C)
                continue;
            if (book[x1][y1] || mapp[x1][y1] == '#')
                continue;
            q.push(node(x1,y1,ss + 1));
            book[x1][y1] = 1;
        }
    }
}

int main()
{
    int S;
    while (scanf("%d",&S) != EOF)
    {
        while (S--)
        {
            scanf("%d %d",&R,&C);
            getchar();
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    scanf("%c",&mapp[i][j]);
                    if (mapp[i][j] == 'J')
                    {
                        jx = i;
                        jy = j;
                    }
                }
                getchar();
            }
            F_dfs();
            int ans = J_dfs();
            if (ans == -1)
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n",ans);

        }
    }
    return 0;
}
