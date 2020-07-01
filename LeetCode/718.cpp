class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int dp[1005][1005] = {0},maxx = 0;
        //最长公共子数组是连续的，故出现两字符不等时直接把dp表那一个位置置为0
        //dp[i][j]表示A以i结尾，B以j结尾（包含i和j）时最长公共子数组
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == B[0]) {
                dp[i][0] = 1;
                maxx = max(1,maxx);
            }
        }
        for(int j = 0; j < B.size(); j++) {
            if(A[0] == B[j]) {
                dp[0][j] = 1;
                maxx = max(1,maxx);
            }
        }
        for(int i = 1; i < A.size(); i++) {
            for(int j = 1; j < B.size(); j++) {
                if(A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxx = max(dp[i][j],maxx);
                }
            }
        }
        return maxx;
    }
};
