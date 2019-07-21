#include <stdio.h>
#include <stdlib.h>

int main()
{
    __int64 a[35];
    int t,i,n;
    a[0]=0;
    a[1]=1;
    a[2]=3;
    for(i=3; i<=30; i++)
        a[i]=a[i-1]+2*a[i-2];
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        printf("%I64d\n",a[n]);
    }
    return 0;
}
