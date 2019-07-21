#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,j,x,b[1000],max;
    char a[1000][20];
    while(scanf("%d",&n))
    {
        getchar();
        if(n==0)
            break;
        for(i=0; i<n; i++)
            scanf("%s",*(a+i));
        for(i=0; i<n; i++)
            for(i=0; i<n; i++)
            {
                x=0;
                for(j=0; j<n; j++)
                {
                    if(strcmp(a[i],a[j])==0)
                    {
                        x++;
                        b[i]=x;
                    }
                }
            }
        max=b[0];
        j=0;
        for(i=0; i<n; i++)
            if(max<b[i])
            {
                max=b[i];
                j=i;
            }
        printf("%s\n",a[j]);
    }
    return 0;
}
