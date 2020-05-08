class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int row = matrix.size(),col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col));
        int i,j,maxx = 0;
        for(i = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i - 1][j - 1],dp[i][j - 1]),dp[i - 1][j]) + 1;//×óÉÏ½Ç£¬×ó£¬ÉÏ
                }
                maxx = max(dp[i][j],maxx);
            }
        }
        return maxx * maxx;
    }
};
