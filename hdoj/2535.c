#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int n,a[105],i,num;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        num=0;
        memset(a,0,sizeof(a));
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        for(i=0; i<=n/2; i++)
        {
            if(a[i]%2==0)
                num=num+a[i]/2+1;
            else
                num=num+(a[i]+1)/2;
        }
        printf("%d\n",num);
    }
    return 0;
}
