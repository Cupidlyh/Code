#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[200];
    int n,i;
    while(gets(a))
    {
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
               a[i]=a[i]-32;
            }
            if(a[i]==' ')
            {
                a[i+1]=a[i+1]-32;
            }
        }

            puts(a);

    }
    return 0;
}
