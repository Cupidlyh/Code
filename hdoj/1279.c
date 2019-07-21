#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int m,flag=0;
            scanf("%d",&m);
            if(m%2!=0)
            {
                printf("%d",m);
                flag=1;
            }
            while(m!=1)
            {
                if(m%2==0)
                {
                    m=m/2;
                    if(m%2!=0&&flag==0&&m!=1)
                    {
                        printf("%d",m);
                        flag=1;
                        continue;
                    }
                    if(m%2!=0&&flag==1&&m!=1)
                        printf(" %d",m);
                }
                else
                {
                    m=m*3+1;
                    if(m%2!=0&&flag==0&&m!=1)
                    {
                        printf("%d",m);
                        flag=1;
                        continue;
                    }
                    if(m%2!=0&&flag==1&&m!=1)
                        printf(" %d",m);
                }
            }
            if(flag==0)
                printf("No number can be output !\n");
            else
                printf("\n");
        }
    }
    return 0;
}
