#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,y_num,r_num;
    char str[30];
    memset(str,0,sizeof(str));
    while(scanf("%d",&n))
    {
        getchar();
        if(n==0)
            break;
        r_num=0;
        y_num=0;
        scanf("%s",str);
        getchar();
        i=0;
        if(str[strlen(str)-1]=='B')
        {
            for(i=0; i<strlen(str)-1; i++)
                if(str[i]=='R')
                    r_num++;
            if(r_num==7)
                printf("Red\n");
            else
                printf("Yellow\n");
        }
        else
        {
            for(i=0; i<strlen(str)-1; i++)
                if(str[i]=='Y')
                    y_num++;
            if(y_num==7)
                printf("Yellow\n");
            else
                printf("Red\n");
        }
        memset(str,0,sizeof(str));
    }
    return 0;
}
