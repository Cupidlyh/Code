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

#define INF 0X3f3f3f3f

int mapp[20][20];//�洢���뵺֮���ʱ��
int book[20];//��ǵ��Ƿ��߹�
int N;

int ans;//���

//����������������ʵ�������õĶ�����
int cur;//��ǰ��״̬�������Ʊ�ʾ��i�����߹���iλ����1������0��
int record[20][1<<15];//record[i][j]��¼���Ǵ�j״̬��i״̬����ָ��Щ���������������Ʊ�ʾ�ģ���i�������ʱ��
//ÿ������״̬��ǣ���һ�����Ķ����ƾ���10��ʮ����ֵ����2����һ�����Ķ����ƾ���100��ʮ����ֵ����4��
//���2 + 4 = 6�������Ʊ�ʾ����110������ľ��ǵ�һ�����͵ڶ������߹��ˣ��Ӻ�������0��ʼ����
int weight[20];

//pre��֮ǰ����������������now�ǵ�ǰ�����������꣬time���Ǳ�����ʱ��
void dfs(int pre,int now,int time)
{
    //now�ǵ�ǰ�����꣬pre����֮ǰ��������������
    //��������N�����������յ㣬��ǰ��now���յ����������
    //�����ж�������pre + 2 == N
    if (pre + 2 == N)
    {
        if (time + mapp[now][N] < ans)
            ans = time + mapp[now][N];
        return ;
    }
    //��֦
    if (time > ans)
        return ;
    for (int i = 2; i < N; i++)
    {
        //��֦
        if (book[i])
            continue;
        //�ж�״̬�Ƿ�֮ǰ���ֹ���С�ģ�Ҳ�Ǽ�֦
        if (record[i][cur + weight[i]] <= time + mapp[now][i])
            continue;
        cur += weight[i];//״̬����
        book[i] = 1;//���
        record[i][cur] = time + mapp[now][i];//����record
        dfs(pre + 1,i,time + mapp[now][i]);
        cur -= weight[i];
        book[i] = 0;
    }
    return ;
}

int main()
{
    //��ʼ��
    for (int i = 1; i <= 16; i++)
    {
        weight[i] = 1 << i;
    }
    while(scanf("%d",&N) != EOF)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d",&mapp[i][j]);
            }
        }
        //��ʼ��
        ans = INF;
        cur = 0;
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 1<<15; j++)
                record[i][j] = INF;
        memset(book,0,sizeof(book));
        dfs(0,1,0);
        printf("%d\n",ans);
    }
    return 0;
}
