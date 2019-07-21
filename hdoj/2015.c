#include <stdio.h>
#include <stdlib.h>

int main()
{   int m,n,i,c,sum,arr,a[100];
    while(scanf("%d%d",&n,&m)!=EOF)
    {   if(n>m)
        {a[0]=0;
     for(i=1;i<=n;i++)
         a[i]=2*i;
         c=n%m;
         sum=0;
         for(i=1;i<=n-c;i++)
         {
             sum=sum+a[i];
             if(i%m==0)
                {arr=sum/m;
             printf("%d",arr);
             sum=0;
                }
             if(i%m==0&&i!=n-c)
                printf(" ");
         }
         if(c!=0)
         {
         for(i=n-c+1;i<=n;i++)
            sum=sum+a[i];
         arr=sum/c;
         printf(" %d\n",arr);
         }
         else
            printf("\n");
        }
        else
        {   sum=0;
            for(i=1;i<=n;i++)
                a[i]=2*i;
            for(i=1;i<=n;i++)
            sum=sum+a[i];
            arr=sum/n;
            printf("%d\n",arr);
        }

    }
    return 0;
}
