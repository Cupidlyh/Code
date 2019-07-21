#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,n,a;
    int b,c;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x==0&&y==0)
        break;
        else
        {c=0;
            for(n=x;n<=y;n++)
            {
                a=n*n+n+41;
                for(b=2;b<=a-1;b++)
                   {if(a%b==0)
                       break;
                       if(a%b!=0&&b==(a-1))
                        c=c+1;
                   }

            }
            if(c==(y-x+1))
                printf("OK\n");
            else
                printf("Sorry\n");
        }
    }
    return 0;
}
