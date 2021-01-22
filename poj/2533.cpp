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
    int N,ans;
    int arr[1005];
    int len[1005];
    while (scanf("%d",&N) != EOF)
    {
        ans = 1;
        for (int i = 0; i < N; i++)
        {
            scanf("%d",&arr[i]);
            len[i] = 1;
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] < arr[i])
                {
                    len[i] = max(len[i],len[j] + 1);
                }
            }
            ans = max(ans,len[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
