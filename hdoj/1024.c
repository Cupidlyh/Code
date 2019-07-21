#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000005
#define max(a,b) ((a)>(b)?(a):(b))

int a[N],dp[N];

int main()
{
    int m,n,i,j,k,sum,temp;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        temp=0;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(i=1; i<=m; i++)
        {
            sum=0;
            for(k=1; k<=i; k++)
                sum+=a[k];
            temp=sum;
            for(j=i+1; j<=n; j++)
            {
                temp=max(dp[j-1],temp)+a[j];
                dp[j-1]=sum;
                sum=max(dp[j-1],temp);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
