#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,c,n;
    scanf("%d",&c);
    while(c--)
    {
        num=0;
        scanf("%d",&n);
        if(n%2==0)
        {
            while(n!=0)
            {
                while(n%2==0)
                {
                    n=n/2;
                }
                num++;
                n--;
            }
        }
        else
        {
            num++;
            n--;
            while(n!=0)
            {
                while(n%2==0)
                {
                    n=n/2;
                }
                num++;
                n--;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
