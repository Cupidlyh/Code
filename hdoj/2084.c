#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    int i,j,k,c,n,sum,a[105][105],b[105][105];
    scanf("%d",&c);
    for(i=0; i<c; i++)
    {
        sum=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(j=1; j<=n; j++)
            for(k=1; k<=j; k++)
                scanf("%d",&a[j][k]);
        for(j=1; j<=n; j++)
        {
            for(k=1; k<=j; k++)
            {
                b[j][k]=a[j][k];
                b[j][k]=max(b[j-1][k],b[j-1][k-1])+b[j][k];
            }
        }
        for(j=1; j<=n; j++)
            sum=max(sum,b[n][j]);
        printf("%d\n",sum);
    }
    return 0;
}
