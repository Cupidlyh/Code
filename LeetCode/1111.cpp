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
        int d = 0;//��¼�����ų��ֵĴ�������Ƕ����ȣ�
        for(char c : seq) {
            if(c == '(') {
                d++;//������d��1
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                d--;//�����Ż�ƥ���һ��������d��1
            }
        }
        return ans;
    }
};
