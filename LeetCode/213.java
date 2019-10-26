package leetcode213;

public class Solution {
	public int rob(int[] nums) {
        if(nums.length == 1)//只有一个房屋时
            return nums[0];
        int dp[] = new int[nums.length + 2];//默认初始化为0
        int dp1[] = new int[nums.length + 2];

        for (int i = 1; i < nums.length; i++)//去掉nums的头元素再遍历nums数组
            dp[i + 2] = Math.max(dp[i] + nums[i], dp[i + 1]);//动态方程

        for (int i = 0; i < nums.length - 1; i++)//去掉nums的尾元素遍历nums数组
            dp1[i + 2] = Math.max(dp1[i] + nums[i], dp1[i + 1]);
        
        return Math.max(dp[nums.length + 1],dp1[nums.length]);//在盗窃第一个房屋和不盗窃第一个房屋这两种情况中选择一个大的
    }
}
