#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i;
    __int64 a[25];
    scanf("%d",&t);
    int n;
    a[1]=1;
    a[2]=2;
    for(i=3; i<20; i++)
        a[i]=a[i-1]+a[i-2];
    while(t--)
    {
        scanf("%d",&n);
        printf("%I64d\n",a[n]);
    }
    return 0;
}
