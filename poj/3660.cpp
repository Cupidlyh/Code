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

int N,M;
//v[i][j]表示i是否大于j
int v[110][110];

//直接暴力逐个判断大小关系
//借助中间值也是允许的，比如说，4>3，3>2，那么4>2
void floyd()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(v[i][k] == 1 && v[k][j] == 1)
                    v[i][j] = 1;
            }
        }
    }
    return ;
}

int main()
{
    while (scanf("%d %d",&N,&M) != EOF)
    {
        memset(v,0,sizeof(v));
        for (int i = 0; i < M; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            v[x][y] = 1;
        }
        floyd();
        int res = 0;
        for (int i = 1; i <= N; i++)
        {
            int temp = 0;
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                    continue;
                //判断当前牛是否可以确定名次
                //如果当前牛比它大的和比它小的之和等于N-1那就可以确定名次
                //v[i][j]判断j是否比i小，v[j][i]判断j是否比i大，二者不可能同时为1（题意说不可能出现环）
                if (v[i][j] == 1 || v[j][i] == 1)
                    temp++;
            }
            if (temp == N - 1)
                res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
