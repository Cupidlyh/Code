#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

char s[15];//�洢��Ŀ�����ַ���
int book[15];//�������
char res[15];//�洢ÿ�����еĽ��

bool cmp(char a,char b)//������
{
    if(a>='A'&&a<='Z'&&b>='A'&&b<='Z')
        return a<b;
    if(a>='a'&&a<='z'&&b<='z'&&b>='a')
        return a<b;
    if(a>='a'&&a<='z'&&b>='A'&&b<='Z')
        return a<(b+32);
    if(a>='A'&&a<='Z'&&b>='a'&&b<='z')
        return (a+32)<=b;//������A<a��һ��
}

void dfs(int len,int bit)//���������н��
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
            //���ź���Ϊ�˱����ظ��ģ�ȥ�أ��ַ�����������a����һ��a���оͿ��ԣ��ڶ���a������
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
