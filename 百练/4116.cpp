#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct node
{
    int x,y,s;
    bool operator<(const node& p) const
    {
        return s > p.s;//小顶堆
    }
    node() {}
    node(int xx,int yy,int ss):x(xx),y(yy),s(ss) {}
};

int main()
{
    int S;
    char mapp[205][205];
    while (scanf("%d",&S) != EOF)
    {
        while (S--)
        {
            int N,M;
            scanf("%d %d",&N,&M);
            getchar();
            int sx,sy;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    scanf("%c",&mapp[i][j]);
                    if (mapp[i][j] == 'r')
                    {
                        sx = i;
                        sy = j;
                    }
                }
                getchar();
            }
            int res = 0;
            int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
            int book[205][205] = {0};
            priority_queue<node>q;//优先队列
            q.push(node(sx,sy,0));
            book[sx][sy] = 1;
            //广度优先搜索
            while (!q.empty())
            {
                int xx = q.top().x;
                int yy = q.top().y;
                int ss = q.top().s;
                q.pop();
                if (mapp[xx][yy] == 'a')
                {
                    res = ss;
                    break;
                }
                for (int i = 0; i < 4; i++)
                {
                    int x1 = xx + coor[i][0];
                    int y1 = yy + coor[i][1];
                    if (x1 < 0 || y1 < 0 || x1 >= N || y1 >= M)
                        continue;
                    if (book[x1][y1] || mapp[x1][y1] == '#')
                        continue;
                    if (mapp[x1][y1] == '@' || mapp[x1][y1] == 'a')
                    {
                        q.push(node(x1,y1,ss + 1));
                        book[x1][y1] = 1;
                    }
                    if (mapp[x1][y1] == 'x')
                    {
                        q.push(node(x1,y1,ss + 2));
                        book[x1][y1] = 1;
                    }
                }
            }
            if (res == 0)
                printf("Impossible\n");
            else
                printf("%d\n",res);
        }
    }
    return 0;
}
