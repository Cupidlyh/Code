#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

#define MAXN 110005

int Manacher(char s[],int len)
{
    char t[MAXN * 2];
    int l = 0;
    //开头加'$'是为了防止越界
    t[l++] = '$';
    t[l++] = '#';
    //在原字符串开头结尾以及字符之间插入一个字符(未在串中出现过的)
    for(int i = 0; i < len; i++)
    {
        t[l++] = s[i];
        t[l++] = '#';
    }
    t[l++] = '\0';
    //p[i] - 1就是t串中以i为中点的回文长度
    vector<int> p(MAXN * 2,0);
    //mx(某回文串延伸到的最右边下标),id(mx所属回文串中心下标)
    int mx = 0,id = 0;
    //bit（结果最大回文串中心下标）,maxlen（最大回文长度）
    int maxlen = 0;
    for(int i = 1; i < l; i++)
    {
        //算法核心
        p[i] = mx > i ? min(p[2 * id - i],mx - i) : 1;
        //一个个进行比较
        //t数组最左边 = '$',最右边 = '\0'，无需判断边界
        while(t[i + p[i]] == t[i - p[i]])
            p[i]++;
        //当t[i]匹配的 右边界超过mx时,mx和id就更新
        if(i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
        //更新结果数据
        if(p[i] > maxlen)
        {
            maxlen = p[i];
        }
    }
    return maxlen - 1;
}

int main()
{
    char s[MAXN];
    while(scanf("%s",s) != EOF)
    {
        int len=strlen(s);
        printf("%d\n",Manacher(s,len));
    }
    return 0;
}
