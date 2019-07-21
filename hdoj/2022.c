#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{int m,n,s,x,y,i,j;
 int a[100][100];
    while(scanf("%d%d",&m,&n)!=EOF)
    {getchar();
      for(i=1;i<=m;i++)
       {
            for(j=1;j<=n;j++)
        {scanf("%d",&a[i][j]);}
       }
        s=a[1][1];
      for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
        {
            if(abs(a[i][j])>abs(s))
            {
                s=a[i][j];
                x=i;
                y=j;
            }
        }
        }
        printf("%d %d %d\n",x,y,s);
    }
    return 0;
}
