#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[1000];
    char b[11];
    int flag,k,i,m,f;
    scanf("%d",&f);
    getchar();
    for(m=0; m<f; m++)
    {
        gets(a);
        flag=0;
        k=0;
        i=0;
        while(a[i]==' ')
            i++;
        b[k]=a[i];
        k++;
        i++;
        while(a[i]!='\0')
        {
            if(a[i]==' ')
                flag=1;
            if(flag==1&&a[i+1]!=' ')
            {
                b[k]=a[i+1];
                k++;
                flag=0;
            }
            i++;
        }
        b[k]='\0';
        for(i=0; i<=k; i++)
            if(b[i]>='a'&&b[i]<='z')
                b[i]=b[i]-32;
        printf("%s\n",b);
    }
    return 0;
}
