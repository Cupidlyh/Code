#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t,i,b,j,flag;
    char a[100];
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        flag=0;
        scanf("%s %d",a,&b);
        for(j=0; j<strlen(a); j++)
            if(a[j]!='.')
                flag=0;
            else
            {
                flag=1;
                break;
            }
        if(flag==0||b>strlen(a)-j-1)
            printf("0\n");
        else
            printf("%c\n",a[j+b]);
    }
    return 0;
}
