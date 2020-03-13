#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());//从小到大排序
        return nums[nums.size() / 2];//因为总存在元素大于n/2，所以直接返回中间处的下标
    }
};
