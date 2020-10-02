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

int coor[5][2] = {0,0,0,1,0,-1,-1,0,1,0};//������������
int M,N;
//mapp��ų�ʼ���̣�turn���ÿ�����ӵķ�ת������ans������Ľ��
int mapp[20][20],turn[20][20],ans[20][20];
//res�����С��ת������cnt��ŵ�ǰ��ת���ܴ���
int res,cnt;

//��ȡ��ǰ�����ɫ��0--��ɫ��1--��ɫ
int getColor(int x,int y)
{
    int temp = mapp[x][y];
    //��Ϊ��ǰ�����ɫ�������Լ���Χ�ĸ���ת������Ӱ��
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

//�ӵڶ���һֱ�ѵ����һ��
void dfs()
{
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (getColor(i - 1,j))
            {
                //turn[i][j] = 1��ʾҪ��ת
                turn[i][j] = 1;
                cnt++;
                //��֦
                if (cnt > res)
                    return ;
            }
        }
    }
    //�ж����һ���Ƿ��ǰ�ɫ
    for (int j = 0; j < N; j++)
        if (getColor(M - 1,j))
            return ;
    //���½��
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
        //���ö�����ö�ٳ���һ������з�ת���
        for (int i = 0; i < 1<<N; i++)
        {
            cnt = 0;
            memset(turn,0,sizeof(turn));
            for (int j = 0; j < N; j++)
            {
                //��ΪҪ�ֵ������ԴӺ���ǰ��
                //turn��¼�ľ��ǵ�ǰ��ķ�ת״̬
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
