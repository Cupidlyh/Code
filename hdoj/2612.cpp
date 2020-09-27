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

struct node
{
    int x,y,s;
    node() {}
    node(int xx,int yy,int ss):x(xx),y(yy),s(ss) {}
};

int n,m;
char mapp[205][205];//存地图
int book[205][205];//标记数组
vector<pair<int,int> >kcf;//存储所有KCF的坐标

//广度优先搜索
void bfs(int sx,int sy,vector<vector<int> >& dict)
{
    int coor[4][2] = {0,1,0,-1,-1,0,1,0};//上下左右
    queue<node> q;
    q.push(node(sx,sy,0));
    book[sx][sy] = 1;
    //确保所有可以到达的KCF都被遍历过
    while (!q.empty())
    {
        int xx = q.front().x;
        int yy = q.front().y;
        int ss = q.front().s;
        q.pop();
        if (mapp[xx][yy] == '@')
        {
            dict[xx][yy] = ss;
        }
        for (int i = 0; i < 4; i++)
        {
            int x1 = xx + coor[i][0];
            int y1 = yy + coor[i][1];
            if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m)
                continue;
            if (mapp[x1][y1] == '#' || book[x1][y1] == 1)
                continue;
            q.push(node(x1,y1,ss + 11));
            book[x1][y1] = 1;
        }
    }
}


int main()
{
    while (scanf("%d %d",&n,&m) != EOF)
    {
        getchar();
        kcf.clear();
        int Yx,Yy,Mx,My;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%c",&mapp[i][j]);
                if (mapp[i][j] == 'Y')
                {
                    Yx = i;
                    Yy = j;
                }
                if (mapp[i][j] == 'M')
                {
                    Mx = i;
                    My = j;
                }
                if (mapp[i][j] == '@')
                {
                    kcf.push_back({i,j});
                }
            }
            getchar();
        }
        //存储M到坐标为[x,y]的KCF的最短时间
        vector<vector<int> >M_dict(205,vector<int>(205,0));
        memset(book,0,sizeof(book));
        bfs(Mx,My,M_dict);
        //存储Y到坐标为[x,y]的KCF的最短时间
        vector<vector<int> >Y_dict(205,vector<int>(205,0));
        memset(book,0,sizeof(book));
        bfs(Yx,Yy,Y_dict);
        int res = INT_MAX;
        //二者相加取最小
        for (int i = 0; i < kcf.size(); i++)
        {
            int r = kcf[i].first;
            int c = kcf[i].second;
            //此题目唯一要注意的点，有可能有些KCF到达不了
            if (M_dict[r][c] == 0 || Y_dict[r][c] == 0)
                continue;
            if (M_dict[r][c] + Y_dict[r][c] < res)
                res = M_dict[r][c] + Y_dict[r][c];
        }
        printf("%d\n",res);
    }
    return 0;
}
