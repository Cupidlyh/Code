#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pre_next(int *next,char *str,int len)
{
    int k=-1,i;
    next[0]=-1;
    for(i=1; i<len; i++)
    {
        while(k>-1&&str[k+1]!=str[i])
            k=next[k];
        if(str[k+1]==str[i])
            k++;
        next[i]=k;
    }
}

int main()
{
    char str[1000]= {0},str1[1000]= {0};
    int next[1000]= {0},k=-1;
    printf("请输入主串，长度不超过1000\n");
    scanf("%s",str);
    printf("请输入子串，长度不超过1000\n");
    scanf("%s",str1);
    int len=strlen(str),len1=strlen(str1),i,ans=0;
    pre_next(next,str1,len1);
    for(i=0; i<len; i++)
    {
        while(k>-1&&str1[k+1]!=str[i])
            k=next[k];
        if(str1[k+1]==str[i])
            k++;
        if(k==len1-1)
        {
            ans=i-len1+1;//只要找到子串第一次出现的位置
            break;//所以跳出循环
        }

        /*int count=0;
        if(k==len1-1)//上面的if判断换成这种就是统计主串中出现了几次子串（不准借助上一个子串中的元素）
        {
            count++;
            k=-1;
        }*/


        /*int count=0;
        if(k==len1-1)//上面的if判断换成这种就是统计主串中出现了几次子串（可以借助上一个子串中的元素）
        {
            count++;
            i=i-len1+1;
            k=-1;
        }*/
    }
    printf("子串首次出现在主串中的序号：%d\n",ans);
    return 0;
}
