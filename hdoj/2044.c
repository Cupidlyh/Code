#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,a,b,i,j;
    __int64 z[50];
    z[1]=1;
    z[2]=2;
    for(i=3; i<50; i++)
        z[i]=z[i-1]+z[i-2];
    scanf("%d",&n);
    for(j=0; j<n; j++)
    {
        scanf("%d%d",&a,&b);
        printf("%I64d\n",z[b-a]);
    }
    return 0;
}
