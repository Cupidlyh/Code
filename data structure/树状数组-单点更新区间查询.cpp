#include <iostream>
#include<algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[50005],c[50005],N;//对应原数组和树状数组

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int i)//求a[1]到a[i]的和(包含a[i])
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
    int i;
    cin>>N;//N为数组中元素个数
    for(i = 1; i <= N; i++)//注意一定要从原始数组下标大于等于1的位置开始存储
    {
        cin>>a[i];
        updata(i,a[i]);//输入初值的时候，也相当于更新了值(利用原数组直接建立树状数组)
    }

    //查询原数组前i项的和（包含第i项）
    printf("%d\n",getsum(i));
    return 0;
}
