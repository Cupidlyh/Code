#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s,i,t,m;
    int a[4];
    while(scanf("%d",&n)!=EOF)
    {   a[0]=1;
        a[1]=1;
        a[2]=1;
        a[3]=1;
        s=0;
        if(n==0)
            break;
        if(n==1)
        printf("1\n");
        if(n==2)
        printf("2\n");
        if(n==3)
        printf("3\n");
        if(n==4)
        printf("4\n");
        if(n>4)
        {for(i=5;i<=n;i++)
          {t=a[1];
           m=a[2];
           a[1]=a[0];
           a[2]=t;
           a[3]=a[3]+m;
           a[0]=a[3];
          }
          s=a[1]+a[2]+a[3]+a[0];
        printf("%d\n",s);
        }
        }
    return 0;
}
