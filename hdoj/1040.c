#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            int i,n,arr[1005];
            scanf("%d",&n);
            for(i=0; i<n; i++)
                scanf("%d",&arr[i]);
            qsort(arr,n,sizeof(arr[0]),cmp);
            for(i=0; i<n; i++)
            {
                if(i==0)
                    printf("%d",arr[i]);
                else
                    printf(" %d",arr[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
