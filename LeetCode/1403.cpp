class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums;
        sort(nums.begin(),nums.end());//从小到大排序
        int i,j;
        int sum = 0,sum1 = 0;
        for(i = nums.size() - 1; i >= 0; i--) {//求数组总和
            sum += nums[i];
        }
        for(i = nums.size() - 1; i >= 0; i--) {
            sum1 += nums[i];//子序列的和
            sum -= nums[i];
            if(sum1 > sum)
                break;
        }
        vector<int>res;
        for(j = nums.size() - 1; j >= i; j--)
            res.push_back(nums[j]);
        return res;
    }
};
