#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a;
    while(scanf("%d",&a))
    {
        if(a==0)
            break;
        int sum=0,i=0,arr;
        while(a)
        {
            arr=a%2;
            a=a/2;
            if(arr==1)
            {
                sum=pow(2,i);
                break;
            }
            i++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
