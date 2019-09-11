#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    int i,n;
    long long int m;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d %d ",a,b);
        int max=0;
        if(a>b)
        {
            max=a;
            a=b;
            b=max;
        }
        max=0;
        for(i=a; i<=b; i++)
        {
            n=1;
            m=i;
            while(m!=1)
            {
                if(m%2==0)
                    m=m/2;
                else
                    m=3*m+1;
                n=n+1;
            }
            max=max>n?max:n;
        }
        printf("%d\n",max);
    }
    return 0;
}
