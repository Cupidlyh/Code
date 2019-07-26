#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr_n[1000005];

void pre_next(int *next,int *arr,int m)
{
    int k=-1;
    next[0]=-1;
    for(int i=1; i<m; i++)
    {
        while(k>-1&&arr[k+1]!=arr[i])
            k=next[k];
        if(arr[k+1]==arr[i])
            k++;
        next[i]=k;
    }
}

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            int n,m,i,k=-1,ans=-1,next[10005]= {0},arr_m[10005]= {0};
            memset(arr_n,0,sizeof(arr_n));
            scanf("%d %d",&n,&m);
            for(i=0; i<n; i++)
                scanf("%d",&arr_n[i]);
            for(i=0; i<m; i++)
                scanf("%d",&arr_m[i]);
            pre_next(next,arr_m,m);
            for(int j=0; j<n; j++)
            {
                while(k>-1&&arr_m[k+1]!=arr_n[j])
                    k=next[k];
                if(arr_m[k+1]==arr_n[j])
                    k++;
                if(k==m-1)
                {
                    ans=j-m+2;
                    break;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
