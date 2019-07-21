#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[32800];

int is_prime(int n)
{
    if(arr[n]==-1)
        return 1;
    if(arr[n]==1)
        return 0;
    int flag=0,i;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        arr[n]=1;
        return 0;
    }
    if(flag==0)
    {
        arr[n]=-1;
        return 1;
    }
}

int main()
{
    int n;
    arr[2]=-1;
    arr[3]=-1;
    arr[4]=1;
    arr[5]=-1;
    while(scanf("%d",&n))
    {

        if(n==0)
            break;
        int i,num=0;
        for(i=2; i<=n/2; i++)
            if(is_prime(i)==1&&is_prime(n-i)==1)
                num++;
        printf("%d\n",num);
    }
    return 0;
}
