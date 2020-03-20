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

int getsum(int i)//求原数组a[i]的值
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
    cin>>N;//N为数组中元素个数
    int i;
    for(i = 1; i <= N; i++)//注意一定要从原始数组下标大于等于1的位置开始存储
    {
        cin>>a[i];
        updata(i,a[i] - a[i - 1]);//输入初值的时候，也相当于更新了值(利用原数组的差分数组(差值数组)建立树状数组)
                                  //原数组{1，2，3，5，6，9}，差值数组为{1，1，1，2，1，3}
    }

    int x,y,k;
    cin>>x>>y>>k;//[x,y]区间内加上k
    updata(x,k);//a[x] - a[x-1]增加k
    updata(y+1,-k);//a[y+1] - a[y]减少k

    //查询i位置的值(即a[i])
    printf("%d\n",getsum(i));
    return 0;
}
