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

int getsum(int i)//��a[1]��a[i]�ĺ�(����a[i])
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
    int i;
    cin>>N;//NΪ������Ԫ�ظ���
    for(i = 1; i <= N; i++)//ע��һ��Ҫ��ԭʼ�����±���ڵ���1��λ�ÿ�ʼ�洢
    {
        cin>>a[i];
        updata(i,a[i]);//�����ֵ��ʱ��Ҳ�൱�ڸ�����ֵ(����ԭ����ֱ�ӽ���)
    }

    //��ѯԭ����ǰi��ĺͣ�������i�
    printf("%d\n",getsum(i));
    return 0;
}
