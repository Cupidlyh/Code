#include <iostream>
#include <cstring>
#include <cmath>
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
    int N,M;
    while(cin>>N>>M)
    {
        if(N == -1 && M == -1)
            break;
        if(gcd(N,M) == 1)//���Լ�����Ϊ1
            cout<<"YES"<<endl;
        else
            cout<<"POOR Haha"<<endl;
    }
    return 0;
}
