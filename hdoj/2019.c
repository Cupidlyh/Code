#include <stdio.h>
#include <stdlib.h>

int main()
{int n,m,a[100],b[101],i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {   if(n==0&&m==0)
    break;
    else
    {for(i=0;i<n;i++)
         scanf("%d",&a[i]);
         i=0;
         j=0;
         for(;i<n;i++,j++)
         {
             if(a[i]<m)
                b[j]=a[i];
                if(a[i]>=m)
                    {b[j]=m;
                    break;
                    }
         }
         j=j+1;
         for(;i<n;i++,j++)
         b[j]=a[i];
         for(j=0;j<n+1;j++)
         {
             if(j!=n)
                printf("%d ",b[j]);
             else
                printf("%d\n",b[j]);
         }

    }

    }
    return 0;
}
