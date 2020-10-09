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

int main()
{
    int W,H;
    while (scanf("%d %d",&W,&H) != EOF)
    {
        getchar();
        if (W == 0 && H == 0)
            break;
        char mapp[25][25];
        int book[25][25] = {0};
        int sx,sy;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
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
        queue<pair<int,int> > q;
        q.push({sx,sy});
        book[sx][sy] = 1;
        //广度优先搜索
        while (!q.empty())
        {
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            if (mapp[xx][yy] == '@' || mapp[xx][yy] == '.')
                res++;
            for (int i = 0; i < 4; i++)
            {
                int x1 = xx + coor[i][0];
                int y1 = yy + coor[i][1];
                if (x1 < 0 || y1 < 0 || x1 >= H || y1 >= W)
                    continue;
                if (mapp[x1][y1] == '#' || book[x1][y1] == 1)
                    continue;
                q.push({x1,y1});
                book[x1][y1] = 1;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
