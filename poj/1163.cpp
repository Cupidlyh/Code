#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int arr[105][105];
    int N,ans;
    while (scanf("%d",&N) != EOF)
    {
        memset(arr,0,sizeof(arr));
        ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    arr[i][j] += arr[i - 1][j];
                    continue;
                }
                if (j == i)
                {
                    arr[i][j] += arr[i - 1][j - 1];
                    continue;
                }
                arr[i][j] += max(arr[i - 1][j - 1],arr[i - 1][j]);
            }
        }
        for (int i = 0; i < N; i++)
            ans = max(ans,arr[N - 1][i]);
        printf("%d\n",ans);
    }
    return 0;
}
