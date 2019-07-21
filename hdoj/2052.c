#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("+");
        for(i=0;i<a;i++)
            printf("-");
        printf("+\n");
        for(i=0;i<b;i++)
        {
            printf("|");
            for(j=0;j<a;j++)
                printf(" ");
            printf("|\n");
        }
        printf("+");
        for(i=0;i<a;i++)
            printf("-");
        printf("+\n\n");
    }
    return 0;
}
