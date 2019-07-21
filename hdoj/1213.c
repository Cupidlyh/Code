#include <stdio.h>
#include <stdlib.h>
int father[1005];

int find(int x)
{
    int r=x;
    while(father[r]!=r)
        r=father[r];
    return r;
}

void Union(int x,int y)
{
    int rx,ry;
    rx=find(x);
    ry=find(y);
    if(rx!=ry)
        father[rx]=ry;
}

int main()
{
    int n,m,t,i;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        if(n==0)
            break;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            father[i]=i;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d %d",&x,&y);
            Union(x,y);
        }
        int count=0;
        for(i=1; i<=n; i++)
            if(father[i]==i)
                count++;
        printf("%d\n",count);
    }
    return 0;
}
