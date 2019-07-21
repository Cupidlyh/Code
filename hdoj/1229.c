#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,k,i,n,p,q,z;
    while(scanf("%d %d %d",&a,&b,&k))
    {
        if(a==0&&b==0)
            break;
        z=10;
        n=10;
        for(i=1; i<k; i++)
            n=n*z;
        p=a%n;
        q=b%n;
        if(p==q)
            printf("-1\n");
        else
            printf("%d\n",a+b);
    }
    return 0;
}
