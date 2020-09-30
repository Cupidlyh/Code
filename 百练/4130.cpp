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
    int x,y,k,s;
    //记录在book[x][y][k]这个状态时哪几个蛇走过
    bool snack[6];
    bool operator<(const node& p) const//小顶堆
    {
        //返回步数最小的，步数相同则返回钥匙树多的
        if (s != p.s)
            return s > p.s;
        return k < p.k;
    }
};

//标记数组
int book[105][105][10];

int main()
{
    int N,M;
    char mapp[105][105];
    while (scanf("%d %d",&N,&M) != EOF)
    {
        if (N == 0 && M == 0)
            break;
        getchar();
        int sx,sy;
        //存储蛇的编号
        map<pair<int,int>,int> snakeBit;
        int num = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%c",&mapp[i][j]);
                if (mapp[i][j] == 'K')
                {
                    sx = i;
                    sy = j;
                }
                if (mapp[i][j] == 'S')
                {
                    snakeBit[ {i,j}] = num++;
                }
            }
            getchar();
        }
        int res = 0;
        int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
        memset(book,0,sizeof(book));
        priority_queue<node>q;
        node start;
        //初始化设置
        start.x = sx;
        start.y = sy;
        start.k = start.s = 0;
        memset(start.snack,0,sizeof(start.snack));
        q.push(start);
        book[sx][sy][0] = 1;
        //广度优先搜索
        while (!q.empty())
        {
            node a = q.top();
            q.pop();
            //救出唐僧的条件
            if (mapp[a.x][a.y] == 'T' && a.k == M)
            {
                res = a.s;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                node b;
                b.x = a.x + coor[i][0];
                b.y = a.y + coor[i][1];
                b.k = a.k;
                //越界
                if (b.x < 0 || b.y < 0 || b.x >= N || b.y >= N)
                    continue;
                //已遍历和走不过的地方
                if (book[b.x][b.y][a.k] || mapp[b.x][b.y] == '#')
                    continue;
                for (int j = 0; j < 6; j++)
                    b.snack[j] = a.snack[j];
                b.s = a.s + 1;
                //蛇没走过的需要额外耗费时间杀死，已经杀死过的就不要杀死第二次（蛇只有一条命）
                if (mapp[b.x][b.y] == 'S' && b.snack[snakeBit[ {b.x,b.y}]] == 0)
                {
                    b.s++;
                    b.snack[snakeBit[ {b.x,b.y}]] = 1;
                }
                //找钥匙
                else if (mapp[b.x][b.y] >= '1' && mapp[b.x][b.y] <= M + '0')
                {
                    int temp = mapp[b.x][b.y] - '0';
                    if (a.k != M && temp == a.k + 1)
                    {
                        b.k++;
                    }
                }
                book[b.x][b.y][b.k] = 1;
                q.push(b);
            }
        }
        if (res == 0)
            printf("impossible\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
