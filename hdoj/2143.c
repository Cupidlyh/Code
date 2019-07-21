#include <stdio.h>
#include <stdlib.h>

int judge(float a,float b,float c)
{
    if(a+b==c)
        return 1;
    if(a-b==c)
        return 1;
    if(b-a==c)
        return 1;
    if(a*b==c)
        return 1;
    if(a!=0)
    {
        if(b/a==c)
            return 1;
        if((int)b%(int)a==(int)c)
            return 1;
    }
    if(b!=0)
    {
        if((int)a%(int)b==(int)c)
            return 1;
        if(a/b==c)
            return 1;
    }
    return 0;
}

int main()
{
    float a,b,c;
    while(scanf("%f %f %f",&a,&b,&c)!=EOF)
    {
        int flag=0;
        while(flag==0)
        {
            if(judge(a,b,c)==1)
            {
                flag=1;
                break;
            }
            if(flag==1)
                break;
            if(judge(b,c,a)==1)
            {
                flag=1;
                break;
            }
            if(flag==1)
                break;
            if(judge(a,c,b)==1)
            {
                flag=1;
                break;
            }
            break;
        }
        if(flag==1)
            printf("oh,lucky!\n");
        else
            printf("what a pity!\n");
    }
    return 0;
}
