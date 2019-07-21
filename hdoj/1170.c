#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,z,y,a,b;
    char c;
    double x,o;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {getchar();
        scanf("%c%d%d",&c,&a,&b);
        if(c=='+')
        {
            z=a+b;
            printf("%d\n",z);
        }
        if(c=='-')
        {
            z=a-b;
            printf("%d\n",z);
        }
        if(c=='*')
        {
            z=a*b;
            printf("%d\n",z);
        }
        if(c=='/')
        {o=(float)a;
            x=o/b;
            y=(int)x;
            if(x==y)
                printf("%0.f\n",x);
            else
            printf("%.2f\n",x);
        }
    }
    return 0;
}
