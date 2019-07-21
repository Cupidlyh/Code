#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i;
    long long a[50];
    while(scanf("%d",&n)!=EOF)
    {
        a[0]=3;
        a[1]=6;
        a[2]=6;
        for(i=3; i<n; i++)
            a[i]=a[i-1]+2*a[i-2];
        printf("%I64d\n",a[n-1]);
    }
    return 0;
}
