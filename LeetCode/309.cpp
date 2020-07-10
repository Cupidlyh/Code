class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(),vector<int>(3,0));
        dp[0][0] = -prices[0];
        //这里的处于冷冻期指的是在第 ii天结束之后的状态。也就是说：如果第 ii天结束之后处于冷冻期，那么第 i+1 天无法买入股票。
        // dp[i][0]: 手上持有股票的最大收益
        // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        for(int i = 1; i < prices.size(); i++) {
             dp[i][0] = max(dp[i - 1][0],dp[i - 1][2] - prices[i]);
             dp[i][1] = dp[i - 1][0] + prices[i];
             dp[i][2] = max(dp[i - 1][1],dp[i - 1][2]);
        }
        return max(dp[prices.size() - 1][1],dp[prices.size() - 1][2]);
    }
};
