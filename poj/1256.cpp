#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

char s[15];//存储题目所给字符串
int book[15];//标记数组
char res[15];//存储每次排列的结果

bool cmp(char a,char b)//排序函数
{
    if(a>='A'&&a<='Z'&&b>='A'&&b<='Z')
        return a<b;
    if(a>='a'&&a<='z'&&b<='z'&&b>='a')
        return a<b;
    if(a>='a'&&a<='z'&&b>='A'&&b<='Z')
        return a<(b+32);
    if(a>='A'&&a<='Z'&&b>='a'&&b<='z')
        return (a+32)<=b;//体现了A<a这一点
}

void dfs(int len,int bit)//深搜找排列结果
{
    if(bit == len)
    {
        res[bit] = '\0';
        printf("%s\n",res);
        return ;
    }
    for(int i = 0; i < len; i++)
    {
        if(book[i] == 0)
        {
            book[i] = 1;
            res[bit] = s[i];
            dfs(len,bit + 1);
            book[i] = 0;
            //已排好序，为了避免重复的，去重（字符串中有两个a，第一个a排列就可以，第二个a跳过）
            while(i + 1 < len && s[i + 1] == s[i])
                i++;
        }
    }
    return ;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        int len = strlen(s);
        sort(s,s + len,cmp);
        dfs(len,0);
    }
    return 0;
}
