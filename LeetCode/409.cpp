#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    //���Ĵ������֣���һ����ÿ����ĸΪż�����ɣ�abba��
    //�ڶ�����������������ĸ�������ģ�������ĸȫΪż�������ɻ��Ĵ�����abbba��
    int longestPalindrome(string s) {
        int big[26] = {0},small[26] = {0},i;//��¼�ַ����д�Сд��ĸ���ִ���
        for(i = 0; i < s.length(); i++) {//�����ַ���ͳ�ƴ�Сд��ĸ����
            if(s[i] >= 'A' && s[i] <= 'Z')
                big[s[i] - 'A']++;
            else
                small[s[i] - 'a']++;
        }
        int flag = 0,res = 0;//flag��������Ƿ�����ĸ���ֵĴ���Ϊ������
        for(i = 0; i < 26; i++) {
            if(big[i] % 2 == 0)
                res += big[i];//ż������������ĸ���Թ��ɻ��Ĵ�
            else {
                flag = 1;
                res += big[i] - 1;//������������һ֮���Ϊż����Ҳ�����������ɻ��Ĵ�
            }
            if(small[i] % 2 == 0)
                res += small[i];
            else {
                flag = 1;
                res += small[i] - 1;
            }
        }
        //flagΪ0��Ϊû�г��������ε���ĸ���Ͳ��üӣ���һ�֣� Ϊ1��Ϊ�У�ֱ�Ӽ������1�Ϳ��ԣ��ڶ��֣�
        return res + flag;
    }
};
