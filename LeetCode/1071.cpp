#include <iostream>

using namespace std;

class Solution {
    bool check(string t,string s) {//判断当前的子串是不是公因子
        string res = "";
        for(int i = 1; i <= s.length() / t.length(); i++)
            res += t;
        return res == s;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(),len2 = str2.length();
        for(int i = min(len1,len2); i >= 1; i--) {//求最大公因子，所以从长的开始枚举
            if(len1 % i == 0 && len2 % i == 0) {//公因子的长度要能被两个字符串整除
                string temp = str1.substr(0,i);//截取子串（公因子）
                if(check(temp,str1) && check(temp,str2))
                    return temp;
            }
        }
        return "";
    }
};
