package leetcode;

class Solution {
    public int combinationSum4(int[] nums, int target) {
        int i,j;
        int[] dp = new int[target+1];//自动将数组里的元素初始化为0
        dp[0]=1;//为了算上数据元素等于target这种情况
        for(i=1;i<=target;i++) {
            for(j=0;j<nums.length;j++) {
                if(i-nums[j]>=0)//就是为了在nums数组中找出和为target的组合
                    dp[i]=dp[i]+dp[i-nums[j]];
            }
        }
        return dp[target];
    }
}
