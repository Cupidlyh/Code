#include <iostream>

using namespace std;

class Solution {
    bool check(string t,string s) {//�жϵ�ǰ���Ӵ��ǲ��ǹ�����
        string res = "";
        for(int i = 1; i <= s.length() / t.length(); i++)
            res += t;
        return res == s;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(),len2 = str2.length();
        for(int i = min(len1,len2); i >= 1; i--) {//��������ӣ����Դӳ��Ŀ�ʼö��
            if(len1 % i == 0 && len2 % i == 0) {//�����ӵĳ���Ҫ�ܱ������ַ�������
                string temp = str1.substr(0,i);//��ȡ�Ӵ��������ӣ�
                if(check(temp,str1) && check(temp,str2))
                    return temp;
            }
        }
        return "";
    }
};
