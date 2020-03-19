#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    //回文串有两种，第一种由每种字母为偶数构成（abba）
    //第二种允许有奇数个字母放在中心，其余字母全为偶数个构成回文串（如abbba）
    int longestPalindrome(string s) {
        int big[26] = {0},small[26] = {0},i;//记录字符串中大小写字母出现次数
        for(i = 0; i < s.length(); i++) {//遍历字符串统计大小写字母数量
            if(s[i] >= 'A' && s[i] <= 'Z')
                big[s[i] - 'A']++;
            else
                small[s[i] - 'a']++;
        }
        int flag = 0,res = 0;//flag用来标记是否有字母出现的次数为奇数次
        for(i = 0; i < 26; i++) {
            if(big[i] % 2 == 0)
                res += big[i];//偶数个次数的字母可以构成回文串
            else {
                flag = 1;
                res += big[i] - 1;//奇数个次数减一之后成为偶数个也可以用来构成回文串
            }
            if(small[i] % 2 == 0)
                res += small[i];
            else {
                flag = 1;
                res += small[i] - 1;
            }
        }
        //flag为0即为没有出现奇数次的字母，就不用加（第一种） 为1即为有，直接加上这个1就可以（第二种）
        return res + flag;
    }
};
