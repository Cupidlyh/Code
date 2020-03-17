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

int getsum(int i)//求a[1]到a[i]的和
{
    int res = 0;
    while(i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void updata(int i,int k)//在i位置加上k（原始数组和树状数组的值都会更改）
{
    a[i] += k;
    while(i <= N)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int main()
{
    cin>>N;//N为数组中元素个数
    int temp;
    for(int i = 1; i <= N; i++)//注意一定要从原始数组下标大于等于1的位置开始存储
    {
        cin>>temp;
        updata(i,temp);//输入初值的时候，也相当于更新了值
    }
    return 0;
}
