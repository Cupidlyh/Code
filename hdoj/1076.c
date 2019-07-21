#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            int y,n,num=0,flag=0;
            scanf("%d %d",&y,&n);
            if(y%400==0)
                flag=1;
            else
            {
                if(y%4==0&&y%100!=0)
                    flag=1;
                else
                    flag=0;
            }
            if(flag==1)
            {
                num++;
                y++;
            }
            while(num!=n)
            {
                flag=0;
                if(y%400==0)
                    flag=1;
                else
                {
                    if(y%4==0&&y%100!=0)
                        flag=1;
                    else
                        flag=0;
                }
                if(flag==1)
                    num++;
                y++;
            }
            printf("%d\n",y-1);
        }
    }
    return 0;
}
