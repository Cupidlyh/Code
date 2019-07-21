#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[50];
    int i,n,j,k;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",a);
        for(j=0; j<strlen(a); j=j+2)
        {
            k=a[j];
            a[j]=a[j+1];
            a[j+1]=k;
        }
        printf("%s\n",a);
    }
    return 0;
}
