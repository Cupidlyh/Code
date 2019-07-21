#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,x,y,z,flag;
    while(scanf("%d",&num)!=EOF)
    {
        flag=0;
        for(x=1; x<=100; x++)
        {
            for(y=1; y<=100; y++)
            {
                for(z=1; z<=100; z++)
                {
                    if(x*x+y*y+z*z==num)
                    {
                        printf("%d %d %d\n",x,y,z);
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
    }
    return 0;
}
