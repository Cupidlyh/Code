#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int N,x,y,sum,ans;
    int arr[1005];
    while (scanf("%d",&N) != EOF)
    {
        for (int k = 1; k <= N; k++)
        {
            scanf("%d %d",&x,&y);
            memset(arr,0,sizeof(arr));
            sum = 0;
            ans = 0;
            for (int i = 0; i < y; i++)
                scanf("%d",&arr[i]);
            sort(arr,arr + y);
            for (int i = y - 1; i >= 0; i--)
            {
                sum += arr[i];
                ans++;
                if (sum >= x)
                {
                    break;
                }
            }
            if (sum >= x)
                printf("Scenario #%d:\n%d\n\n",k,ans);
            else
                printf("Scenario #%d:\nimpossible\n\n",k);
        }
    }
    return 0;
}
