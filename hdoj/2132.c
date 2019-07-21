#include <stdio.h>
#include <stdlib.h>

__int64 a[100005];

int main()
{
    a[1]=1;
    int n;
    __int64 i;
    for(i=2; i<=100000; i++)
        if(i%3==0)
            a[i]=a[i-1]+i*i*i;
        else
            a[i]=a[i-1]+i;
    while(scanf("%d",&n))
    {
        if(n<0)
            break;
        printf("%I64d\n",a[n]);
    }
    return 0;
}
