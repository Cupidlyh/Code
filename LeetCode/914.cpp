#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int num[10005] = {0},i;
        for(i = 0; i < deck.size(); i++)//����deck��¼ÿ��Ԫ�س��ֵĴ���
            num[deck[i]]++;
        int X = -1;//��¼���Լ��
        for(i = 0; i < 10000; i++) {
            if(num[i] > 0 && X == -1) {//X�ȼ�¼�׸����ִ�����Ϊ0�Ĵ���
                X = num[i];
                continue;
            }
            if(num[i] > 0)//�����Լ��
                X = gcd(X,num[i]);
        }
        return X >= 2;//X >= 2����true,���򷵻�false
    }
};
