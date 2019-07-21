#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,n,j;
    __int64 a[31];
    a[1]=1;
    a[2]=3;
    j=1;
    for(i=3; i<=30; i++)
    {
        a[i]=a[i-1]+2*a[i-2];
        j=j+2;
    }
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        printf("%I64d\n",a[n]);
    }
    return 0;
}
