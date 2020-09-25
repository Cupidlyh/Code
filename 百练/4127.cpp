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
    //迷宫
    int maze[5][5] =
    {

        0, 1, 0, 0, 0,

        0, 1, 0, 1, 0,

        0, 0, 0, 0, 0,

        0, 1, 1, 1, 0,

        0, 0, 0, 1, 0,

    };
    int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
    //记录迷宫此点是由哪个点走过来的（此点路径的的上一个点）
    vector<vector<pair<int,int> > > dict(5,vector<pair<int,int> >(5));
    queue<pair<int,int> > q;
    q.push({0,0});
    int book[5][5] = {0};
    book[0][0] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == 4 && y == 4)
            break;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + coor[i][0];
            int yy = y + coor[i][1];
            if (xx < 0 || yy < 0 || xx >= 5 || yy >= 5)
                continue;
            if (book[xx][yy] || maze[xx][yy])
                continue;
            dict[xx][yy] = {x,y};
            book[xx][yy] = 1;
            q.push({xx,yy});
        }
    }
    //存储结果，从终点往前找（每个点的路径的前一个点一定唯一）
    vector<pair<int,int> > res;
    res.push_back({4,4});
    while (true)
    {
        int x = res.back().first;
        int y = res.back().second;
        if (x == 0 && y == 0)
            break;
        res.push_back(dict[x][y]);
    }
    //翻转
    reverse(res.begin(),res.end());
    for (int i = 0; i < res.size(); i++)
    {
        printf("(%d, %d)\n",res[i].first,res[i].second);
    }
    return 0;
}
