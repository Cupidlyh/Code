#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int s,d,flag=0,i;
        scanf("%d %d",&s,&d);
        for(i=0; i<=(s+1)/2; i++)
        {
            if(abs(i-(s-i))==d)
            {
                flag=1;
                if(s-i>i)
                    printf("%d %d\n",s-i,i);
                else
                    printf("%d %d\n",i,s-i);
                break;
            }
        }
        if(flag==0)
            printf("impossible\n");
    }
    return 0;
}
