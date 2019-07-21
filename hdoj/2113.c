#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int sum,i,k=0;
    char a[100];
    while(scanf("%s",a)!=EOF)
    {

        k++;
        sum=0;
        for(i=0; i<strlen(a); i++)
            if(a[i]%2==0)
                sum=sum-48+(int)a[i];
        if(k==1)
            printf("%d\n",sum);
        else
            printf("\n%d\n",sum);
    }
    return 0;
}
