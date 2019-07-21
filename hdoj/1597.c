#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[36]= {1,1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6,1,2,3,4,5,6,7,1,2,3,4,5,6,7,8};
    int b[9]= {1,2,3,4,5,6,7,8,9};
    int t;
    __int64 n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        if(n<=36)
            printf("%d\n",a[n-1]);
        else
        {
            printf("%d\n",b[n%37-1]);
        }
    }
    return 0;
}
