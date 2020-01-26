#include <iostream>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int num = 0,i,n;
        for(i = 0; i < nums.size(); i++) {
            n = log10(nums[i]) + 1;//计算数字的位数
            if(n % 2 == 0)
                num++;
        }
    return num;
    }
};
