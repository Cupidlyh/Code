#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j,n,m,k;
    int i,a,b;
    scanf("%d",&k);
    for(j=0; j<k; j++)
    {
        m=1;
        b=1;
        a=1;
        scanf("%d",&n);
        if(n==1||n==2)
            m=1;
        else
        {
            for(i=3; i<=n; i++)
            {
                b=a;
                a=m;
                m=a+b;
            }
        }
        printf("%d\n",m);
    }
    return 0;
}
