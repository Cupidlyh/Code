#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int res[100005] = {0};//打表（存储100005以内所有数字的最小生成元）
int main()
{
    for(int i = 0; i < 100005; i++)
    {
        int temp = i,sum = i;
        while(temp)//计算和
        {
            sum += temp % 10;
            temp /= 10;
        }
        if(i < res[sum] || res[sum] == 0)//生成元更新
            res[sum] = i;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        printf("%d\n",res[N]);//查表输出
    }
    return 0;
}
