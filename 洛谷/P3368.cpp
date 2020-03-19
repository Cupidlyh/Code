#include <iostream>
#include<algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[500005],c[500005],N;//对应原数组和树状数组

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i)//求a[i]的值
{
    int res = 0;
    while(i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k)//在i位置加上k（此函数只更改树状数组的值，若要更改原数组的值需要在主函数中实现）
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
        updata(i,a[i] - a[i - 1]);//输入初值的时候，也相当于更新了值
    }
    while(M--)
    {
        int o,x,y,k;
        scanf("%d",&o);
        if(o == 1)
        {
            scanf("%d %d %d",&x,&y,&k);
            updata(x,k);//a[x] - a[x-1]增加k
            updata(y + 1,-k);//a[y+1] - a[y]减少k

        }
        if(o == 2)
        {
            scanf("%d",&x);
            printf("%d\n",getsum(x));
        }
    }
    return 0;
}
