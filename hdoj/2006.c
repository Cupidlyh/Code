#include <stdio.h>
#include <stdlib.h>

int main()
{   int a,i,b,sum;
    while(scanf("%d",&a)!=EOF)
 {  sum=1;
    for(i=1;i<=a;i++)
    {
      scanf("%d",&b);
      if(b%2!=0)
      {
         sum=sum*b;
      }
      if(i==a)
      printf("%d\n",sum);
    }

 }
      return 0;
}
