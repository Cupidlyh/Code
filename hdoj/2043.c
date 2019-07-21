#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[51];
    int n,y,flag,i,x,z,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",a);
        flag=0;
        x=0;
        y=0;
        z=0;
        for(j=0; j<strlen(a); j++)
        {
            if(a[j]>='0'&&a[j]<='9')
                x++;
            else if(a[j]>='a'&&a[j]<='z')
                y++;
            else if(a[j]>='A'&&a[j]<='Z')
                z++;
        }
        if(x>0)
            flag++;
        if(y>0)
            flag++;
        if(z>0)
            flag++;
        if(x+y+z<strlen(a))
            flag++;
        if(strlen(a)>=8&&strlen(a)<16&&flag>=3)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
