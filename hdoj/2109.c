#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        int i,chi=0,jap=0,arr[105]= {0},arr1[105]= {0};
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        for(i=0; i<n; i++)
            scanf("%d",&arr1[i]);
        qsort(arr,n,sizeof(arr[0]),cmp);
        qsort(arr1,n,sizeof(arr1[0]),cmp);
        for(i=0; i<n; i++)
        {
            if(arr[i]>arr1[i])
                chi=chi+2;
            if(arr[i]==arr1[i])
            {
                chi++;
                jap++;
            }
            if(arr[i]<arr1[i])
                jap=jap+2;
        }
        printf("%d vs %d\n",chi,jap);
    }
    return 0;
}
