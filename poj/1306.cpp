#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int N,M;
    while (scanf("%d %d",&N,&M) != EOF)
    {
        if (N == 0 && M == 0)
            break;
        long long int ans = 1;
        int temp;
        int N_M = N - M;
        int maxx,minn;
        if (N_M >= M)
        {
            maxx = N_M;
            minn = M;
        }
        else
        {
            maxx = M;
            minn = N_M;
        }
        temp = 1;
        for (int i = maxx + 1; i <= N; i++)
        {
            ans *= i;
            if (temp <= minn)
            {
                ans /= temp;
                temp++;
            }
        }
        while (temp <= minn)
        {
            ans /= temp;
            temp++;
        }
        printf("%d things taken %d at a time is %lld exactly.\n",N,M,ans);
    }
    return 0;
}
