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
        for(string s : words) {//��תÿ�����ʴ浽reverse_words��
            reverse(s.begin(),s.end());
            reverse_words.push_back(s);
        }
        sort(reverse_words.begin(), reverse_words.end());//�ֵ�������
        int res = 0,len = words.size();
        for(int i = 0; i < len; i++) {
            if(i + 1 < len && reverse_words[i + 1].find(reverse_words[i]) == 0)//��ǰ��������һ�����ʵ�ǰ׺������
                continue;
            else
                res += reverse_words[i].length() + 1;//���ʳ��ȼ���һ�� '#' �ĳ���
        }
        return res;
    }
};
