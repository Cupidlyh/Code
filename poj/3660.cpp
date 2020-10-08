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
//v[i][j]��ʾi�Ƿ����j
int v[110][110];

//ֱ�ӱ�������жϴ�С��ϵ
//�����м�ֵҲ������ģ�����˵��4>3��3>2����ô4>2
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
                //�жϵ�ǰţ�Ƿ����ȷ������
                //�����ǰţ������ĺͱ���С��֮�͵���N-1�ǾͿ���ȷ������
                //v[i][j]�ж�j�Ƿ��iС��v[j][i]�ж�j�Ƿ��i�󣬶��߲�����ͬʱΪ1������˵�����ܳ��ֻ���
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
