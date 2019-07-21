#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m=0,sum,a,i;
    while(scanf("%d",&n))
    {
        if(n<=0)
            break;
        m++;
        sum=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a);
            sum=sum+a;
        }
        printf("Sum of #%d is %d\n",m,sum);
    }
    return 0;
}
