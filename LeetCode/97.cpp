class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())//长度不等时直接返回false
            return false;
        //dp[i][j]表示s1的前i个字符和s2的前j个字符能否交叉组成s3前i+j个字符
        vector<vector<int>> dp(s1.length() + 1,vector<int>(s2.length() + 1,0));
        dp[0][0] = 1;//前0个字符肯定是可以匹配的
        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                if(i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
                    dp[i][j] = dp[i - 1][j];
                if(j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
