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
        for(int i = 2; i <= n; i++)//最后一轮剩下2个人，所以从2开始反推
            ans = (ans + m) % i;
        return ans;
    }
};
