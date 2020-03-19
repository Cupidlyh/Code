#include <iostream>
#include<algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[500005],c[500005],N;//��Ӧԭ�������״����

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i)//��a[i]��ֵ
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
    int M,i;
    scanf("%d %d",&N,&M);
    for(i = 1; i <= N; i++)
    {
        scanf("%d",&a[i]);
        updata(i,a[i] - a[i - 1]);//�����ֵ��ʱ��Ҳ�൱�ڸ�����ֵ
    }
    while(M--)
    {
        int o,x,y,k;
        scanf("%d",&o);
        if(o == 1)
        {
            scanf("%d %d %d",&x,&y,&k);
            updata(x,k);//a[x] - a[x-1]����k
            updata(y + 1,-k);//a[y+1] - a[y]����k

        }
        if(o == 2)
        {
            scanf("%d",&x);
            printf("%d\n",getsum(x));
        }
    }
    return 0;
}
