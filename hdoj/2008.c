#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,c,d,e;
    float b[100];
    while(scanf("%d",&n)!=EOF)
    {   if(n==0)
         break;
        if(n>0)
        {c=0;
         d=0;
         e=0;
        for(a=1;a<=n;a++)
       {
           scanf("%f",&b[a]);
        if(b[a]<0)
            c=c+1;
        if(b[a]==0)
            d=d+1;
        if(b[a]>0)
            e=e+1;
       }
        printf("%d %d %d\n",c,d,e);
        }
    }
    return 0;
}
