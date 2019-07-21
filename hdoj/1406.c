#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,i,j,k;
    int sum,x;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        x=0;
        scanf("%d%d",&a,&b);
        if(a>b)
        {
            k=a;
            a=b;
            b=k;
        }
        for(j=a; j<=b; j++)
        {
            sum=0;
            for(k=1; k<j; k++)
            {
                if(j%k==0)
                    sum=sum+k;
            }
            if(sum==j)
                x=x+1;
        }
        printf("%d\n",x);
    }
    return 0;
}
