#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        if(n % m == 0)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
