#include <iostream>

using namespace std;

int gcd(int n,int m)//辗转相除法求最大公约数
{
    int temp;
    while(m > 0)
    {
        temp = n % m;
        n = m;
        m = temp;
    }
    return n;
}

/*
int gcd(int n,int m)//求最大公约数递归写法
{
    if(m == 0)
        return n;
    return gcd(m,n % m);
}
*/

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        cout<<gcd(n,m)<<endl;
    }
    return 0;
}
