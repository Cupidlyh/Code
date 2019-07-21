#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int z,a[10000],i,j,k,flag,n;
    while(scanf("%d",&z))
    {
        k=0;
        n=0;
        a[k++]=2;
        a[k++]=3;
        if(z==0)
            break;
        for(i=3; i<=z; i++)
        {
            flag=0;
            for(j=2; j<=sqrt(i); j++)
            {
                if(i%j!=0)
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                a[k++]=i;
        }
        for(i=0; i<k-1; i++)
            for(j=i+1; j<k; j++)
                if(a[i]+a[j]==z)
                    n++;
        if(z==2)
            printf("0\n");
        else
            printf("%d\n",n);
    }
    return 0;
}
