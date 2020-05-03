class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0,maxx = nums[0];
        //动态规划方程dp[i] = max(dp[i-1] + nums[i],nums[i])
        //dp[i]代表以第i个数结尾的连续子数组的最大和,最终结果就是在dp数组中选择最大值
        //观察方程发现可以变成空间消耗为1的写法，如下：
        for(int i = 0; i < nums.size(); i++) {
            prev = max(prev + nums[i],nums[i]);
            maxx = max(prev,maxx);
        }
        return maxx;
    }
};
