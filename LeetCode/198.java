package leetcode198;

public class Solution {
	public int rob(int[] nums) {
        int dp[] = new int[nums.length + 2];//默认初始化为0
        for(int i = 0; i < nums.length; i++) 
            dp[i + 2] = Math.max(dp[i] + nums[i], dp[i + 1]);//动态方程
        return dp[nums.length + 1]; 
    }
}
