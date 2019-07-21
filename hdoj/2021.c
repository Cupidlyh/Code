#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],n,i,s,x,y;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        s=0;
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(i=1; i<=n; i++)
        {
            y=a[i];
            x=0;
            if(y>=100)
            {
                x=y/100;
                y=y%100;
                s=s+x;
            }
            if(y>=50&&y<100)
            {
                x=y/50;
                y=y%50;
                s=s+x;
            }
            if(y>=10&&y<50)
            {
                x=y/10;
                y=y%10;
                s=s+x;
            }
            if(y>=5&&y<10)
            {
                x=y/5;
                y=y%5;
                s=s+x;
            }
            if(y>=2&&y<5)
            {
                x=y/2;
                y=y%2;
                s=s+x;
            }
            if(y==1)
                s=s+y;
        }
        printf("%d\n",s);
    }
    return 0;
}
