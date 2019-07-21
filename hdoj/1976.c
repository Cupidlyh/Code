#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,j;
    while(scanf("%d",&t)!=EOF)
    {
        for(j=0; j<t; j++)
        {
            int arr[5]= {0},arr1[5]= {0},i;
            for(i=1; i<=3; i++)
                scanf("%d",&arr[i]);
            for(i=1; i<=3; i++)
                scanf("%d",&arr1[i]);
            if(arr[1]>arr1[1])
                printf("First\n");
            if(arr[1]<arr1[1])
                printf("Second\n");
            if(arr[1]==arr1[1])
            {
                if(arr[2]>arr1[2])
                    printf("First\n");
                if(arr[2]<arr1[2])
                    printf("Second\n");
                if(arr[2]==arr1[2])
                {
                    if(arr[3]>arr1[3])
                        printf("First\n");
                    if(arr[3]<arr1[3])
                        printf("Second\n");
                    if(arr[3]==arr1[3])
                        printf("Same\n");
                }
            }
        }
    }
    return 0;
}
