#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[205],let;
    memset(str,0,sizeof(str));
    while(scanf("%c" "%s",&let,str)!=EOF)
    {
        getchar();
        int len=strlen(str),i,num=0;
        for(i=0; i<len; i++)
            if(str[i]==let||str[i]-32==let||str[i]+32==let)
                num++;
        printf("%.5lf\n",(double)num/len);
        memset(str,0,sizeof(str));
    }
    return 0;
}
