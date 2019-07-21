#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i,t,j;
    int a[100];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        else
        {for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            if(abs(a[i])<abs(a[j]))
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
          for(i=0;i<n;i++)
          {
              if(i!=(n-1))
                printf("%d ",a[i]);
              else
                printf("%d\n",a[i]);
          }
        }
    }
    return 0;
}
