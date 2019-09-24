package leetcode;

class Solution {
	public int combinationSum4(int[] nums, int target) {
        int i,j;
        int[] dp = new int[target+1];
        dp[0]=1;
        for(i=1;i<=target;i++) {
            for(j=0;j<nums.length;j++) {
                if(i>=nums[j])
                    dp[i]=dp[i]+dp[i-nums[j]];
            }
        }
        return dp[target];
    }
}
