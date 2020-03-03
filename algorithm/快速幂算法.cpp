#include <iostream>
#define ll long long
using namespace std;

ll qpow(ll a,ll n)//求a^n
{
    ll res = 1;
    while(n > 0) {
        if(n % 2 == 1)
            res = res * a;
        a = a * a;
        n = n / 2;
    }
    return res;
}

/*
ll qpow(ll a,ll n,ll mod)//求a^n % mod
{
    ll res = 1;
    while(n > 0) {
        if(n % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n = n / 2;
    }
    return res % mod;
}
*/


int main()
{

    return 0;
}
