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

char mapp[10][10];
int row[10];//��Ǵ����Ƿ�������
int col[10];//��Ǵ����Ƿ�������
int n,k,res;

//�����������
//x��������п�ʼ�ң�num�������Ӹ���
void dfs(int x,int num)
{
    if (num == k + 1)
    {
        res++;
        return ;
    }
    for (int i = x; i < n; i++)
    {
        if (!row[i])
        {
            for (int j = 0; j < n; j++)
            {
                if (!col[j])
                {
                    if (mapp[i][j] == '.')
                        continue;
                    row[i] = 1;
                    col[j] = 1;
                    dfs(i + 1,num + 1);
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
    }
    return ;
}

int main()
{
    while (scanf("%d %d",&n,&k) != EOF)
    {
        if (n == -1 && k == -1)
            break;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        res = 0;
        getchar();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%c",&mapp[i][j]);
            }
            getchar();
        }
        dfs(0,1);
        printf("%d\n",res);
    }
    return 0;
}
