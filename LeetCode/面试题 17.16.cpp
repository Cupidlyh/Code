#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        vector<int>dp(nums.size() + 1,0);
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];//dp[i] ��ʾnums[0...i] �ܵõ����ʱ��
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            //��������Ϊֹ�����ֵ���������ȡ�ϴ�
            //1��ԤԼ���Σ�����һ�β�ԤԼ��dp[i-2] + nums[i]��
            //2�����β�ԤԼ����ֵΪԤԼ����һ�ε����ֵ
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
