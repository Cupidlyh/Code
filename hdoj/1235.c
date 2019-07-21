#include <stdio.h>
#include <stdlib.h>
int a[1005];
int main()
{
    int n,i,j,m;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        j=0;
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=0; i<n; i++)
            if(a[i]==m)
                j++;
        printf("%d\n",j);
    }
    return 0;
}
