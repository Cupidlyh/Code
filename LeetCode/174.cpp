class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        //dp[i][j] 表示从坐标 (i,j) 到终点所需的最小初始值。
        //换句话说，当我们到达坐标 (i,j) 时，如果此时我们的路径和不小于dp[i][j]，我们就能到达终点
        dp[n - 1][m - 1] =  max(1 - dungeon[n - 1][m - 1],1);
        for(int j = m - 2; j >= 0; --j) {//最后一行先初始化
            dp[n - 1][j] = max(dp[n - 1][j + 1] - dungeon[n - 1][j],1);
        }
        for(int i = n - 2; i >= 0; --i) {//最后一列先初始化
            dp[i][m - 1] = max(dp[i + 1][m - 1] - dungeon[i][m - 1],1);
        }
        //从右下到左上进行动态规划
        for(int i = n - 2; i >= 0; --i) {
            for(int j = m - 2; j >= 0; --j) {
                int minn = min(dp[i][j + 1],dp[i + 1][j]);
                dp[i][j] = max(minn - dungeon[i][j],1);
            }
        }
        return dp[0][0];
    }
};
