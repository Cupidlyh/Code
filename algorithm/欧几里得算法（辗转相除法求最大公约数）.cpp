#include <iostream>

using namespace std;

int gcd(int n,int m)//շת����������Լ��
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


int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        cout<<gcd(n,m)<<endl;
    }
    return 0;
}
