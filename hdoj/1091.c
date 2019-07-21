#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,sum;
            while(scanf("%d%d",&a,&b)!=EOF)
           {if(a==0&&b==0)
             break;
            else
            {sum=a+b;
            printf("%d\n",sum);}
           }
    return 0;
}
