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
        for(i = 0; i < deck.size(); i++)//遍历deck记录每个元素出现的次数
            num[deck[i]]++;
        int X = -1;//记录最大公约数
        for(i = 0; i < 10000; i++) {
            if(num[i] > 0 && X == -1) {//X先记录首个出现次数不为0的次数
                X = num[i];
                continue;
            }
            if(num[i] > 0)//求最大公约数
                X = gcd(X,num[i]);
        }
        return X >= 2;//X >= 2返回true,否则返回false
    }
};
