#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

/*
* 求最长回文子串
*/
string Manacher(string &s)
{
    //开头加'$'是为了防止越界
    string t = "$#";
    //在原字符串开头结尾以及字符之间插入一个字符(未在串中出现过的)
    for(int i = 0; i < s.length(); i++)
    {
        t += s[i];
        t += '#';
    }
    //p[i] - 1就是t串中以i为中点的回文长度
    vector<int> p(t.length(),0);
    //mx(某回文串延伸到的最右边下标),id(mx所属回文串中心下标)
    int mx = 0,id = 0;
    //bit（结果最大回文串中心下标）,maxlen（最大回文长度）
    int bit,maxlen = 0;
    for(int i = 1; i < t.length(); i++)
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
            bit = i;
        }
    }
    return s.substr((bit - maxlen) / 2,maxlen - 1);
    //return maxlen - 1;
}
/*
* abaaba
* i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13
* t[i]:  $ # a # b # a # a # b  #  a  #
* p[i]:  1 1 2 1 4 1 2 7 2 1 4  1  2  1
*/
int main()
{
    string s;
    s.resize(1000);//具体问题具体规模
    while(scanf("%s",&s[0]) != EOF)
    {
        Manacher(s);
    }
    return 0;
}
