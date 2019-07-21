#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[11]= {0};
    __int64 i,sum,j;
    a[0]=1;
    a[1]=1;
    for(i=2; i<=9; i++)
        a[i]=i*a[i-1];
    for(i=1; i<=3628800; i++)
    {
        sum=0;
        j=i;
        while(j/10!=0)
        {
            sum=sum+a[j%10];
            j=j/10;
        }
        sum=sum+a[j];
        if(sum==i)
            printf("%I64d\n",i);
    }
    return 0;
}
