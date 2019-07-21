#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,num,n,k,i,a[1005]= {0};
    scanf("%d",&t);
    while(t--)
    {
        num=0;
        scanf("%d %d",&n,&k);
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(i=1; i<=n; i++)
            if(a[i]>a[k])
                num++;
        printf("%d\n",num);
    }
    return 0;
}
