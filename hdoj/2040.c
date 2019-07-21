#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,n,i,j,s,flag,flag1;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        flag1=0;
        s=0;
        flag=0;
        scanf("%d %d",&a,&b);
        for(j=1; j<a; j++)
            if(a%j==0)
                s=s+j;
        if(s==b)
            flag=1;
        s=0;
        for(j=1; j<b; j++)
            if(b%j==0)
                s=s+j;
        if(s==a)
            flag1=1;
        if(flag1==1&&flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
