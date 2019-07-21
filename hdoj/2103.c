#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,m,n,i,j,a[31],p,flag;
    __int64 sum,b;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d",&m,&n);
        for(j=0; j<n; j++)
            scanf("%d",&a[j]);
        flag=0;
        for(p=0; p<m; p++)
        {
            if(a[p]==1)
            {
                flag=1;
                break;
            }
        }
        sum=0;
        b=10000;
        if(flag==1)
        {
            for(j=p+1; j<n; j++)
            {
                sum=sum+b;
                b=b*2;
            }
        }
        if(flag==0)
        {
            for(j=p; j<n; j++)
            {

                sum=sum+b;
                b=b*2;
            }
        }
        printf("%I64d RMB\n",sum);
    }
    return 0;
}
