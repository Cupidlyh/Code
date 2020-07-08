class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        //dp[i][j]表示字符串s的前i个字符和模式p的前j个字符是否能匹配
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        //定义空字符串可以匹配
        dp[0][0] = 1;
        //因为'*'可匹配空字符串，所以开头连续的'*'是可以匹配s前0个字符
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = 1;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];//或运算（'*'匹配空和任意字符串两种情况）
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
