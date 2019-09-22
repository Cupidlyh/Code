#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,k,flag=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&k);
            if(k==1)
            {
                flag=1;
            }
        }
        if(flag==1)
            printf("HARD\n");
        else
            printf("EASY\n");
    }
    return 0;
}
