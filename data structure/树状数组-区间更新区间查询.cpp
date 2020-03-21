#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int N;//数组元素个数
int a[100005];//原数组
int c[100005];
int c1[100005];

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i)//求前缀和（即a[1]到a[i]的和）
{
    int res = 0;
    int x = i;
    while(i > 0)
    {
        res += x * c[i] - c1[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k)//在i位置加上k（此函数只更改树状数组的值，若要更改原数组的值需要在主函数中实现）
{
    int x = i;//因为x不变，所以得先保存i值
    while(i <= N)
    {
        c[i] += k;
        c1[i] += k * (x - 1);
        i += lowbit(i);
    }
}

int main()
{
    int i;
    scanf("%d",&N);
    for(i = 1; i <= N; i++)
    {
        scanf("%d",&a[i]);
        updata(i,a[i] - a[i - 1]);//输入初值的时候，也相当于更新了值
    }


    int x,y,z;


    scanf("%d %d",&x,&y);
    printf("%d\n",getsum(y) - getsum(x - 1));//求[x,y]区间和




    scanf("%d %d %d",&x,&y,&z);
    //[x,y]区间内加上z
    updata(x,z);//a[x] - a[x-1]增加z
    updata(y + 1,-z);//a[y+1] - a[y]减少z

    return 0;
}
