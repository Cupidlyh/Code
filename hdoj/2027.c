#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,j,a,b,c,d,e,f;
    char x[100];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
       {
        gets(x);
         a=0;
         b=0;
         c=0;
         d=0;
         e=0;
         f=strlen(x);
        for(j=0;j<f;j++)
        {if(x[j]=='a')
           a=a+1;
         if(x[j]=='e')
           b=b+1;
         if(x[j]=='i')
           c=c+1;
         if(x[j]=='o')
           d=d+1;
         if(x[j]=='u')
           e=e+1;
        }
        if(i==0)
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n\n",a,b,c,d,e);
        if(i==(n-1))
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,b,c,d,e);
        if(i!=0&&i!=(n-1))
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n\n",a,b,c,d,e);
       }
    return 0;
}
