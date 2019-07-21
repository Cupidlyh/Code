#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,o;
    while(scanf("%d%d",&m,&n)!=EOF)
    { j=0;
      o=0;
      if(m<n)
     {for(i=m;i<=n;i++)
     {
            if(i%2==0)
            o=o+i*i;
            else
            j=j+i*i*i;
     }
     printf("%d %d\n",o,j);}
     if(m>n)
     {
       for(i=n;i<=m;i++)
     {
            if(i%2==0)
            o=o+i*i;
            else
            j=j+i*i*i;
     }
     printf("%d %d\n",o,j);
     }
    }
    return 0;
}
