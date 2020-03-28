#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<string>reverse_words;
        for(string s : words) {//反转每个单词存到reverse_words中
            reverse(s.begin(),s.end());
            reverse_words.push_back(s);
        }
        sort(reverse_words.begin(), reverse_words.end());//字典序排序
        int res = 0,len = words.size();
        for(int i = 0; i < len; i++) {
            if(i + 1 < len && reverse_words[i + 1].find(reverse_words[i]) == 0)//当前单词是下一个单词的前缀，丢弃
                continue;
            else
                res += reverse_words[i].length() + 1;//单词长度加上一个 '#' 的长度
        }
        return res;
    }
};
