#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,t,n,j;
    __int64 sum,v;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        sum=0;
        v=1;
        for(j=1; j<=n; j++)
        {
            sum=sum+v;
                v=v+2;
            sum=sum%10000;
        }
        printf("%I64d\n",sum);

    }
    return 0;
}
