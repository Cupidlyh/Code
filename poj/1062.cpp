#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define N 109
#define MIN(a,b) a>b?b:a

struct node//�洢���˱���ļ۸�����˵ĵȼ�
{
    int money;
    int level;
} no[N];

int m,n;
int Graph[N][N];//�洢�㵽�����Ϣ
long long int length[N];//��¼��Դ�㵽�յ�ĵ�ǰ���ٽ����
int sign[N];//��ǵ��Ƿ���ʹ�
int limit[N];//��ǵ��Ƿ����ƣ����ܲ��뽻����

int dijkastra()//�Ͻ�˹�����㷨
{
    memset(sign,0,sizeof(sign));
    int i,v,w,minn;
    for(v = 1; v <= n; v++)
        length[v] = INT_MAX;
    length[1] = 0;

    for(i = 2; i <= n; i++)
    {
        minn = INT_MAX;
        for(w = 1; w <= n; w++)
        {
            if(sign[w] == 0 && length[w] <= minn && limit[w])//ѡ��һ����ǰ�Ļ������ٵ�·�����յ�Ϊv
            {
                v = w;
                minn = length[w];
            }
        }
        sign[v] = 1;
        for(w = 1; w <= n; w++)//���´�������������v-s�����ж�������ٽ����
        {
            if((length[v] + Graph[v][w] < length[w]) && limit[w] && sign[w] == 0)
            {
                length[w] = length[v] + Graph[v][w];//����length[w]
            }
        }
    }
    int ans = INT_MAX;
    for(i = 1; i <= n; i++)//�������������Ľ��
    {
        length[i] = length[i] + no[i].money;
        ans = MIN(ans,length[i]);
    }
    return ans;
}

int main()
{
    scanf("%d %d",&m,&n);
    int i,j;
    for(i = 0; i < N; i++)//��ʼ��GraphΪ�������ֵ�����Ա�ʾ������
        for(j = 0; j < N; j++)
            Graph[i][j] = INT_MAX;
    for(i = 1; i <= n; i++)
    {
        int p,l,x;
        scanf("%d %d %d",&p,&l,&x);
        no[i].money = p;
        no[i].level = l;
        for(j = 0; j < x; j++)
        {
            int t,v;
            scanf("%d %d",&t,&v);
            Graph[i][t] = v;
        }
    }
    int ans = INT_MAX,kinglevel = no[1].level;
    //ö�ٵȼ�����
    for(i = 0; i <= m; i++)
    {
        memset(limit,0,sizeof(limit));
        for(j = 1; j <= n; j++)
        {
            if((no[j].level >= kinglevel - m + i) && (no[j].level <= kinglevel + i))
                limit[j] = 1;
        }
        ans = MIN(ans,dijkastra());
    }
    printf("%d",ans);
    return 0;
}
