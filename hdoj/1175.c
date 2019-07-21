#include <stdio.h>
#include <stdlib.h>
int a[1005][1005];
int main()
{
    int n,m,b,c,d,e,i,j,q,k;
    while(scanf("%d %d",&n,&m))
    {
        if(m==0&&n==0)
            break;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                scanf("%d",&a[i][j]);
        scanf("%d",&q);
        int flag;
        for(k=0; k<q; k++)
        {
            flag=1;
            scanf("%d %d %d %d",&b,&c,&d,&e);
            if(a[b][c]==0||a[d][e]==0)
                flag=0;
            if(a[b][c]!=a[d][e])
                flag=0;
            if(flag==0)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}
