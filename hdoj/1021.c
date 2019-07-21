#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1000005];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(arr,0,sizeof(arr));
        arr[0]=7;
        arr[1]=11;
        for(int i=2; i<=n; i++)
            arr[i]=(arr[i-1]+arr[i-2])%3;
        if(arr[n]%3==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
