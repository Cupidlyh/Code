#include <stdio.h>
#include <stdlib.h>

int main()
{
    __int64 arr[2500]= {0};
    int i,n;
    arr[1]=1;
    for(i=3; i<=2345; i=i+2)
        arr[i]=arr[i-2]+i*i;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",arr[n]);
    }
    return 0;
}
