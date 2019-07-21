#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[105]= {0},i,sum,j;
    arr[0]=1;
    for(i=1; arr[i-1]!=0; i++)
        scanf("%d",&arr[i]);
    printf("PERFECTION OUTPUT\n");
    for(i=1; arr[i-1]!=0; i++)
    {
        if(arr[i]==0)
            continue;
        sum=0;
        printf("%5d",arr[i]);
        for(j=1; j<=(arr[i]+1)/2; j++)
            if(arr[i]%j==0)
                sum=sum+j;
        if(sum==arr[i])
            printf("  PERFECT\n");
        if(sum>arr[i])
            printf("  ABUNDANT\n");
        if(sum<arr[i])
            printf("  DEFICIENT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
