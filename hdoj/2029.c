#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,m,p,x;
    char a[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {scanf("%s",a);
         m=strlen(a)-1;
         p=0;
         x=0;
         while(p<(m+1)/2)
         {
             if(a[p]==a[m])
                x=x+1;
             p++;
             m--;
         }
          if(x==p)
            printf("yes\n");
          else
            printf("no\n");
        }
    }
    return 0;
}
