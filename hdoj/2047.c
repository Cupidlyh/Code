#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i;
    __int64 z[41];
    z[1]=3;
    z[2]=8;
    for(i=3; i<40; i++)
        z[i]=2*z[i-1]+2*z[i-2];
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",z[n]);
    }
    return 0;
}
