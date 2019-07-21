#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        int arr[1005]= {0},arr1[1005]= {0},temp=0;
        int i=0;
        while(scanf("%d %d",&arr[i],&arr1[i]))
        {
            if(arr[i]==0&&arr1[i]==0)
            {
                break;
            }
            i++;
        }
        int j;
        for(j=0; j<i; j++)
            if(arr[j]==m)
                temp=arr1[j];
        qsort(arr1,i,sizeof(arr1[0]),cmp);
        int jac=1;
        for(j=0; j<i; j++)
        {
            if(arr1[j]>temp)
                jac++;
        }
        printf("%d\n",jac);
    }
    return 0;
}
