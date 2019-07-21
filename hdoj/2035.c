#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i,b,x,t;
    while(scanf("%d%d",&a,&b)!=EOF)
    {if(a==0&&b==0)
     break;
     else
     {t=1;
     for(i=0;i<b;i++)
        {x=t%1000;
        t=x*a;
        }
     }
     x=t%1000;
     printf("%d\n",x);
    }
    return 0;
}
