#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,j,k;
    char a[50];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(a);
        j=strlen(a);
        for(k=0;k<j;k++)
        {
            if(a[0]>='0'&&a[0]<='9')
            {
                printf("no\n");
                break;
            }
            if((a[k]>='a'&&a[k]<='z')||a[k]=='_');
               else
                  if((a[k]>='0'&&a[k]<='9')||(a[k]>='A'&&a[k]<='Z'));
                else
            {
                printf("no\n");
                break;
            }
            if(k==(j-1))
                printf("yes\n");
        }
    }
    return 0;
}
