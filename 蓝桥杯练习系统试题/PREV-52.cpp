#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define ll long long
using namespace std;

ll qpow(ll a,ll n,ll mod)//利用快速幂求a^n % mod
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

//res = [a/b*10^(n+2)]%1000
//因为公式：x/d%m = x%(d*m)/d
//所以res = [a*10^(n+2)]%(b*1000)/b 
int main() {
	ll a,b,n;
	cin>>a>>b>>n;
	ll b1 = b * 1000;
	ll temp = qpow(10,n + 2,b1);
	ll res = ((a % b1 * temp) % b1) / b;
	cout<<res<<endl;
	return 0;
}
