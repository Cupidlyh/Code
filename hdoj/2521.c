#include <stdio.h>
#include <stdlib.h>
int z[5005];
int main()
{
    int t,a,b,i,j,num,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        for(i=a; i<=b; i++)
        {
            num=0;
            for(j=1; j<=i; j++)
            {
                if(i%j==0)
                    num++;
            }
            z[i]=num;
        }
        flag=z[a];
        for(i=a; i<=b; i++)
        {
            if(z[i]>flag)
                flag=z[i];
        }
        for(i=a; i<=b; i++)
            if(z[i]==flag)
            {
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
