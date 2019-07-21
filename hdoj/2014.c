#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    double arr,sum,max,min;
    double a[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
         scanf("%lf",&a[i]);
         sum=0;
         for(i=0;i<n;i++)
            sum=sum+a[i];
            max=0.0;
            min=100.0;
            for(i=0;i<n;i++)
                {if(a[i]>max)
                   max=a[i];
                 if(a[i]<min)
                      min=a[i];}
                sum=sum-max-min;
         arr=sum/(n-2.0);
        printf("%.2f\n",arr);
    }
    return 0;
}
