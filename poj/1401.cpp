#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

//求n！结果末尾0的个数就是求1-n中5这个因子的个数
int z(int n)
{
    int ans = 0,i;
    //n/i计算的是[1,n]中有多少数字是i的倍数（因子中包含i）
    //就比如说1到50有10个数字包含因子5，2个数字因子包含25
    //因为计算的是因子5的数量，5这种包含一次因子5，25包含两个因子5，所以这么计算
    for(i = 5; i <= n; i *= 5)
        ans += n / i;
    return ans;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",z(n));
    }
    return 0;
}
