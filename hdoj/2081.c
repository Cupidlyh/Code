#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,j,i;
    char a[2300];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
      {gets(a);
      printf("6");
      for(j=6;j<11;j++)
      if(j==10)
      printf("%c\n",a[j]);
      else
      printf("%c",a[j]);
      }
    return 0;
}
