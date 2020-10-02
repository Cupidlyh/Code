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

int coor[5][2] = {0,0,0,1,0,-1,-1,0,1,0};//自身，上下左右
int M,N;
//mapp存放初始棋盘，turn存放每个棋子的翻转次数，ans存放最后的结果
int mapp[20][20],turn[20][20],ans[20][20];
//res存放最小翻转次数，cnt存放当前翻转的总次数
int res,cnt;

//获取当前点的颜色，0--白色，1--黑色
int getColor(int x,int y)
{
    int temp = mapp[x][y];
    //因为当前点的颜色受自身以及周围四个翻转次数的影响
    for (int i = 0; i < 5; i++)
    {
        int xx = x + coor[i][0];
        int yy = y + coor[i][1];
        if (xx < 0 || yy < 0 || x >= M || yy >= N)
            continue;
        temp += turn[xx][yy];
    }
    return temp % 2;
}

//从第二层一直搜到最后一层
void dfs()
{
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (getColor(i - 1,j))
            {
                //turn[i][j] = 1表示要翻转
                turn[i][j] = 1;
                cnt++;
                //剪枝
                if (cnt > res)
                    return ;
            }
        }
    }
    //判断最后一层是否都是白色
    for (int j = 0; j < N; j++)
        if (getColor(M - 1,j))
            return ;
    //更新结果
    if (cnt < res)
    {
        memcpy(ans,turn,sizeof(turn));
        res = cnt;
    }
    return ;
}

int main()
{
    while (scanf("%d %d",&M,&N) != EOF)
    {
        res = INT_MAX;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                scanf("%d",&mapp[i][j]);
        //利用二进制枚举出第一层的所有翻转情况
        for (int i = 0; i < 1<<N; i++)
        {
            cnt = 0;
            memset(turn,0,sizeof(turn));
            for (int j = 0; j < N; j++)
            {
                //因为要字典序，所以从后往前填
                //turn记录的就是当前点的翻转状态
                turn[0][N - 1 - j] = i>>j&1;
                if (turn[0][N - 1 - j])
                    cnt++;
            }
            dfs();
        }
        if (res == INT_MAX)
            printf("IMPOSSIBLE");
        else
        {
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (j == 0)
                        printf("%d",ans[i][j]);
                    else
                        printf(" %d",ans[i][j]);
                }
                printf("\n");
            }
        }

    }
    return 0;
}
