#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1000005];

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        memset(arr,0,sizeof(arr));
        int i,res=0;
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        for(i=0; i<n; i++)
            res=res^arr[i];
        printf("%d\n",res);
    }
    return 0;
}
