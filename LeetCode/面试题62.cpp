#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i = 2; i <= n; i++)//���һ��ʣ��2���ˣ����Դ�2��ʼ����
            ans = (ans + m) % i;
        return ans;
    }
};
