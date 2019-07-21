#include <stdio.h>
int main()
{
int n,sum,i;
while(scanf("%d",&n)!=EOF)
{
sum=0;
for(i=1;i<=n;i++)
sum=sum+i;
printf("%d\n\n",sum);
}
return 0;
}
