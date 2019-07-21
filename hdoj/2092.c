#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        int i,flag=0;
        if(m<0)
        {
            for(i=m; i<-m; i++)
            {
                if(i==0)
                    continue;
                if(m%i==0)
                {
                    if(i+m/i==n)
                    {
                        flag=1;
                        break;
                    }

                }
            }
        }
        if(m==0)
            flag=1;
        if(m>0)
        {
            for(i=-m; i<=m; i++)
            {
                if(i==0)
                    continue;
                if(m%i==0)
                {
                    if(i+m/i==n)
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
