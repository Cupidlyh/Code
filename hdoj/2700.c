#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[35];
    int num,len;
    memset(str,0,sizeof(str));
    while(scanf("%s",str))
    {
        if(str[0]=='#')
            break;
        num=0;
        len=strlen(str);
        int i;
        if(str[len-1]=='e')
        {
            for(i=0; i<len-1; i++)
            {
                if(str[i]=='1')
                    num++;
            }
            if(num%2==0)
                str[len-1]='0';
            else
                str[len-1]='1';
        }
        else
        {
            for(i=0; i<len-1; i++)
            {
                if(str[i]=='1')
                    num++;
            }
            if(num%2==0)
                str[len-1]='1';
            else
                str[len-1]='0';
        }
        printf("%s\n",str);
        memset(str,0,sizeof(str));
    }
    return 0;
}
