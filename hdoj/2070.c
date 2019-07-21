#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    __int64 a,b,s;
    while(scanf("%d",&n))
    {
        if(n==-1)
            break;
        a=0;
        b=1;
        if(n==0)
            s=0;
        if(n==1)
            s=1;
        if(n>1)
        {
            for(i=2; i<=n; i++)
            {
                s=a+b;
                a=b;
                b=s;
            }
        }
        printf("%I64d\n",s);
    }
    return 0;
}
