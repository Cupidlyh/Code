#include <stdio.h>
#include <stdlib.h>

int n,num,map[11];

void dfs(int k)
{
    int i,j,flag;
    if(k==n+1)
    {
        num++;
        return;
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            map[k]=i;
            flag=1;
            for(j=1; j<k; j++)
            {
                if(map[j]==i||i-k==map[j]-j||i+k==map[j]+j)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                dfs(k+1);
        }
    }
}

int main()
{
    int m,arr[11]= {0};
    for(n=1; n<=10; n++)
    {
        num=0;
        dfs(1);
        arr[n]=num;
    }
    while(scanf("%d",&m))
    {
        if(m==0)
            break;
        else
            printf("%d\n",arr[m]);
    }
    return 0;
}
