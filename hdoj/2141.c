#include <stdio.h>
#include <stdlib.h>
#define maxn 510
int a[maxn],b[maxn],c[maxn],ab[maxn*maxn];
int l,n,m,k;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int judge(int y)
{
    int left=0,right=k;
    while(left<right)
    {
        int mid;
        mid=left+(right-left)/2;
        if(ab[mid]<y)
            left=mid+1;
        else if(ab[mid]>y)
            right=mid;
        else
            return 1;
    }
    return 0;
}

int main()
{
    int cas=1;
    int i,j;
    while(scanf("%d %d %d",&l,&n,&m)!=EOF)
    {
        printf("Case %d:\n",cas++);
        for(i=0; i<l; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++)
            scanf("%d",&b[i]);
        for(i=0; i<m; i++)
            scanf("%d",&c[i]);
        k=0;
        for(i=0; i<l; i++)
            for(j=0; j<n; j++)
                ab[k++]=a[i]+b[j];
        qsort(ab,k,sizeof(ab[0]),cmp);
        int s,x;
        scanf("%d",&s);
        for(i=0; i<s; i++)
        {
            int flag=0;
            scanf("%d",&x);
            for(j=0; j<m; j++)
            {
                int y;
                y=x-c[j];
                if(judge(y))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
