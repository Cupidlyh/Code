class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
        for(int i = 0; i < triangle.size(); ++i)
            dp[i].resize(triangle[i].size());
        dp[0][0] = triangle[0][0];
        //自顶向下的进行动态规划
        for(int i = 1; i < triangle.size(); ++i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                if(j - 1 < 0 && j < triangle[i - 1].size())
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                else if(j - 1 >= 0 && j >= triangle[i - 1].size())
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j],dp[i - 1][j - 1]);
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < dp[dp.size() - 1].size(); ++i)
            res = min(res,dp[dp.size() - 1][i]);
        return res;
    }
};
