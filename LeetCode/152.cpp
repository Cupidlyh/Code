class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>dpmax(nums.size(),0);
        vector<int>dpmin(nums.size(),0);
        int i,maxx = nums[0];
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        //因为数组中存在负数，所以有可能出现负负得正的情况，所以要用两个数组记录中间值
        //两个数组动的态规划方程就是for循环中的方程，maxx记录最大值
        for(i = 1; i < nums.size(); i++) {
            dpmin[i] = min(min(nums[i],nums[i] * dpmin[i - 1]),dpmax[i - 1] * nums[i]);
            dpmax[i] = max(max(nums[i],nums[i] * dpmax[i - 1]),dpmin[i - 1] * nums[i]);
            maxx = max(maxx,dpmax[i]);
        }
        return maxx;
    }
};
