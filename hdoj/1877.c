#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m,i;
    __int64 a,b,arr[1000]= {0},sum;
    while(scanf("%d",&m))
    {
        if(m==0)
            break;
        scanf("%I64d %I64d",&a,&b);
        sum=a+b;
        if(a==0&&b==0)
            printf("0");
        else
        {
            i=0;
            while(sum)
            {
                arr[i++]=sum%m;
                sum=sum/m;
            }
            while(i--)
                printf("%I64d",arr[i]);
        }
        printf("\n");
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
