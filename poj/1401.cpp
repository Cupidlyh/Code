#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

//��n�����ĩβ0�ĸ���������1-n��5������ӵĸ���
int z(int n)
{
    int ans = 0,i;
    //n/i�������[1,n]���ж���������i�ı����������а���i��
    //�ͱ���˵1��50��10�����ְ�������5��2���������Ӱ���25
    //��Ϊ�����������5��������5���ְ���һ������5��25������������5��������ô����
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
