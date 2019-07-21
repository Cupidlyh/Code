#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i;
    __int64 z[51];
    z[1]=1;
    z[2]=2;
    for(i=3; i<=50; i++)
        z[i]=z[i-1]+z[i-2];
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",z[n]);
    }
    return 0;
}
