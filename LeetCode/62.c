#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n){
    int dp[m][n],i,j;//dp[i][j]是到达i,j的最多路径
    for(i = 0; i < m; i++)//第零列只有一条路径可以到达
        dp[i][0] = 1;
    for(i = 0; i < n; i++)//第零行只有一条路径可以到达
        dp[0][i] = 1;
    for(i = 1; i < m; i++)
        for(j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];//动态方程
    return dp[m-1][n-1];
}
