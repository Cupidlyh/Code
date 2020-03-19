#include <iostream>
#include<algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[50005],c[50005],N;//��Ӧԭ�������״����

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i)//��ԭ����a[i]��ֵ
{
    int res = 0;
    while(i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k)//��iλ�ü���k���˺���ֻ������״�����ֵ����Ҫ����ԭ�����ֵ��Ҫ����������ʵ�֣�
{
    while(i <= N)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int main()
{
    cin>>N;//NΪ������Ԫ�ظ���
    int i;
    for(i = 1; i <= N; i++)//ע��һ��Ҫ��ԭʼ�����±���ڵ���1��λ�ÿ�ʼ�洢
    {
        cin>>a[i];
        updata(i,a[i] - a[i - 1]);//�����ֵ��ʱ��Ҳ�൱�ڸ�����ֵ(����ԭ����Ĳ��(��ֵ)����)
    }

    int x,y,k;
    cin>>x>>y>>k;//[x,y]�����ڼ���k
    updata(x,k);//a[x] - a[x-1]����k
    updata(y+1,-k);//a[y+1] - a[y]����k

    //��ѯiλ�õ�ֵ(��a[i])
    printf("%d\n",getsum(i));
    return 0;
}
