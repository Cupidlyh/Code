package leetcode72;

class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        //当字符串 word1 的长度为 i，字符串 word2 的长度为 j 时，将 word1 转化为 word2 所使用的最少操作次数为 dp[i] [j]
        int [][] dp = new int[n1 + 1][n2 + 1];
        int i,j;
        //当word1字符串为空时，只能进行插入操作
        for(i = 1; i <= n2; i++)
            dp[0][i] = dp[0][i - 1] + 1;
        //当word2字符串为空时，只能进行删除操作
        for(i = 1; i <= n1; i++)
            dp[i][0] = dp[i - 1][0] + 1;
        //遍历两个字符串
        for(i = 1; i <= n1; i++) {
            for(j = 1; j <= n2; j++) {
                if(word1.charAt(i - 1) == word2.charAt(j - 1))//字符相等，不需要进行任何操作
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;//在删除，插入，替换中选择一个最小的
            }
        }
        return dp[n1][n2];
    }
}
