#include <stdio.h>
#include <stdlib.h>

int main()
{   char a,b,c;
    int bj(char x,char y,char z);
    while(scanf("%c%c%c\n",&a,&b,&c)!=EOF)
    {
     bj(a,b,c);
    }
    return 0;
}

int bj(char x,char y,char z)
{   char m;
    if(x>y)
    {m=x;
    x=y;
    y=m;
    }
    if(x>z)
    {
        m=x;
        x=z;
        z=m;
    }
    if(y>z)
    {
        m=y;
        y=z;
        z=m;
    }
    printf("%c %c %c\n",x,y,z);
    return(x,y,z);
}
