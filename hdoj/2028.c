#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,c,i,t,k,x;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&a);
        x=a;
        for(i=1; i<n; i++)
        {
            scanf("%d",&b);
            k=b;
            if(a<b)
            {
                t=a;
                a=b;
                b=t;
            }
            while(b!=0)
            {
                t=a%b;
                a=b;
                b=t;
                c=a;
            }
            a=x/c*k;
            x=a;
        }
        printf("%d\n",a);
    }
    return 0;
}
