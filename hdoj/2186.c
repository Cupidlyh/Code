#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,sum,c,q,y;
    scanf("%d",&c);
    while(c--)
    {
        sum=0;
        scanf("%d",&n);
        q=n/2;
        if(q%10==0)
            sum=sum+q/10;
        else
            sum=sum+1+(q-(q%10))/10;
        y=(n-q)*2/3;
        if(y%10==0)
            sum=sum+y/10;
        else
            sum=sum+1+(y-(y%10))/10;
        n=n-q-y;
        if(n%10==0)
            sum=sum+n/10;
        else
            sum=sum+1+(n-(n%10))/10;
        printf("%d\n",sum);
    }
    return 0;
}
