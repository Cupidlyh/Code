#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        int arr[1000]= {0},i,time;
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        time=5*n+6*arr[0];
        for(i=1; i<n; i++)
            if(arr[i]>arr[i-1])
                time=time+(arr[i]-arr[i-1])*6;
            else
                time=time+(arr[i-1]-arr[i])*4;
        printf("%d\n",time);
    }
    return 0;
}
