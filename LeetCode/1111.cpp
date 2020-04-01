#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int d = 0;//记录左括号出现的次数（即嵌套深度）
        for(char c : seq) {
            if(c == '(') {
                d++;//左括号d加1
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                d--;//右括号会匹配掉一个左括号d减1
            }
        }
        return ans;
    }
};
