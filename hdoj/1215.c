#include <stdio.h>
#include <stdlib.h>
 __int64 s,a[500001];
int main()
{
    int i,t,j,k,n;
    for(i=1; i<=500000; i++)
    {
        s=0;
        for(j=1; j<=i/2; j++)
            if(i%j==0)
                s=s+j;
        a[i]=s;
    }
    scanf("%d",&t);
    for(k=0; k<t; k++)
    {
        scanf("%d",&n);
        printf("%I64d\n",a[n]);
    }
    return 0;
}
