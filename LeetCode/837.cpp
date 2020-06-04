class Solution {
public:
    double new21Game(int N, int K, int W) {
        double sum = 0,i;
        vector<double> dp(K + W,0);
        //dp[x]为她手上牌面为x时，能获胜的概率是：dp[x]=1/w * (dp[x+1]+dp[x+2]+dp[x+3]...+dp[x+w])
        //获胜条件是小于等于N，而分数大于等于K就停止抽牌
        //所以手里牌为大于等于K，小于等于N时，获胜概率都为1
        for (i = K; i < K + W && i <= N; i++) {
            dp[i] = 1.0;
            sum += dp[i];
        }
        //从式子可以看出，我们可以从后往前动态规划
        for(i = K - 1; i >= 0; i--) {
            dp[i] = sum / W;//求值
            sum = sum - dp[i + W] + dp[i];//减去末尾的，加上现在的（维持是W个之和）
        }
        return dp[0];
    }
};
