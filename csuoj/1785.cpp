#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d",&n);
        int arr[4] = {0};
        int j,k,res = 0;
        double num = 0.0;
        for(j = 3; j >= 0; j--)
        {
            arr[j] = n % 10;
            n /= 10;
        }
        for(j = 0; j < 4; j++)
        {
            int temp = arr[j];
            for(k = 0; k <= 9; k++)
            {
                if(j == 0 && k == 0)
                    continue;
                if(temp == k)
                    continue;
                arr[j] = k;
                num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
                if(sqrt(num) - int(sqrt(num)) == 0)
                {
                    res++;
                }
            }
            arr[j] = temp;
        }
        printf("Case %d: %d\n",i,res);
    }
    return 0;
}
