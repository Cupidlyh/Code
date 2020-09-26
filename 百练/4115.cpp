#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int x,y;
    int t;
    int s;
    node() {}
    node(int xx,int yy,int tt,int ss):x(xx),y(yy),t(tt),s(ss) {}

};

//标记[x,y]点有k个查克拉的鸣人是否走过
int book[205][205][15];

int main()
{
    int M,N,T;
    while (scanf("%d %d %d",&M,&N,&T) != EOF)
    {
        getchar();
        char mapp[205][205];
        memset(book,0,sizeof(book));
        int sx,sy;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%c",&mapp[i][j]);
                if (mapp[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
            }
            getchar();
        }

        int res = 0;
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
        queue<node> q;
        q.push(node(sx,sy,T,0));
        book[sx][sy][T] = 1;
        //广度优先搜索
        while (!q.empty())
        {
            int xx = q.front().x;
            int yy = q.front().y;
            int tt = q.front().t;
            int ss = q.front().s;
            q.pop();
            if (mapp[xx][yy] == '+')
            {
                res = ss;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int x1 = xx + coor[i][0];
                int y1 = yy + coor[i][1];
                if (x1 < 0 || y1 < 0 || x1 >= M || y1 >= N)
                    continue;
                if (book[x1][y1][tt])
                    continue;
                if (tt == 0)
                {
                    if (mapp[x1][y1] == '*' || mapp[x1][y1] == '+')
                    {
                        q.push(node(x1,y1,tt,ss + 1));
                        book[x1][y1][tt] = 1;
                    }
                }
                else
                {
                    if (mapp[x1][y1] == '*' || mapp[x1][y1] == '+')
                    {
                        q.push(node(x1,y1,tt,ss + 1));
                        book[x1][y1][tt] = 1;
                    }
                    if (mapp[x1][y1] == '#')
                    {
                        q.push(node(x1,y1,tt - 1,ss + 1));
                        book[x1][y1][tt - 1] = 1;
                    }
                }
            }
        }
        if (res == 0)
            printf("-1\n");
        else
            printf("%d\n",res);
    }
    return 0;
}


