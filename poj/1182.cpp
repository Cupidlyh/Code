#include <iostream>
#include<cstdio>
using namespace std;

int father[50005];//��¼��ǰ�ڵ�ĸ��ڵ�
int sum[50005];//��¼��ǰ�ڵ㵽���ڵ�Ĺ�ϵ

int Find(int x)//��ѯx�ĸ��ڵ㣬·��ѹ�������¹�ϵ
{
    if(father[x] != x)
    {
        int temp = father[x];
        father[x] = Find(father[x]);
        sum[x] = (sum[x] + sum[temp]) % 3;
    }
    return father[x];
}

int main()
{
    int N,K,d,x,y,i,num = 0;
    scanf("%d %d",&N,&K);
    for(i = 0; i <= N; i++)//�����ʼ��
    {
        father[i] = i;
        sum[i] = 0;
    }
    for(i = 0; i < K; i++)
    {
        scanf("%d %d %d",&d,&x,&y);
        if(x > N || y > N)//�ڶ�������ļٻ�
        {
            num++;
            continue;
        }
        if(d == 2 && x == y)//����������ļٻ�
        {
            num++;
            continue;
        }
        int rx = Find(x);
        int ry = Find(y);
        if(rx != ry)//���Ϻϲ�
        {
            father[rx] = ry;
            sum[rx] = (d - 1 +  sum[y] - sum[x] + 3) % 3;
        }
        else//��һ������ļٻ�
        {
            if(d == 1)
            {
                if(sum[x] != sum[y])//x��y��ͬ�࣬���ڵ�Ҳһ�������Թ�ϵӦ����ͬ
                {
                    num++;
                    continue;
                }
            }
            if(d == 2)
            {
                if((sum[x] - sum[y] + 3) % 3 != d - 1)//x��y�����ڵ�һ����ͨ��������ϵ�Ƴ���ʽ
                {
                    num++;
                    continue;
                }
            }
        }
    }
    printf("%d\n",num);
    return 0;
}
