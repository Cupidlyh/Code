#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,a,b,c,d,e,f,g,u,v;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        v=e=a*d+b*c;
        u=f=b*d;
        g=0;
        do
        {
            g=e%f;
            e=f;
            f=g;
        }while(g!=0);
        printf("%d %d\n",v/e,u/e);
    }
    return 0;
}
