#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int arr[10001]= {0},i;
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        qsort(arr,n,sizeof(arr[0]),cmp);
        printf("%d\n",arr[(n-1)/2]);
    }
    return 0;
}
