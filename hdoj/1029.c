#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000005

int a[N],dp[N];

int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,-1,sizeof(a));
        memset(dp,-1,sizeof(dp));
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        i=1;
        j=2;
        while(j<=n)
        {
            if(dp[i]==1)
                while(dp[i]==1)
                    i++;
            if(a[i]!=a[j])
            {
                dp[i]=1;
                dp[j]=1;
                i++;
                j++;
            }
            else
            {
                while(a[i]==a[j])
                    j++;
            }
        }
        i=1;
        while(dp[i]==1&&i<n)
            i++;
        printf("%d\n",a[i]);
    }
    return 0;
}
