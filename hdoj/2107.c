#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    __int64 a[100];
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%I64d",&a[i]);
        __int64 max=a[0];
        for(i=0; i<n; i++)
            if(max<a[i])
                max=a[i];
        printf("%I64d\n",max);
    }
    return 0;
}
