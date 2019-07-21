#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,m,n,i,f;
    while(scanf("%d%d",&m,&n)!=EOF)
    {   f=1;
        for(i=m;i<=n;i++)
        {
            a=i/100;
            b=i/10%10;
            c=i%10;
            if(a*a*a+b*b*b+c*c*c==i)
            {f=f+1;
                if(f==2)
                {printf("%d",i);}
                if(f>2)
                {printf(" %d",i);}
            }
                if(i==n)
                {
                     if(f==1)
                  {printf("no");}
                  printf("\n");
                }

        }
    }
    return 0;
}

