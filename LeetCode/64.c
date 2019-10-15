#include <stdio.h>
#include <stdlib.h>

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i,j,dp[gridSize][*gridColSize];
    dp[0][0] = grid[0][0];
    for(i = 1; i < gridSize; i++)//第零列的最小路径和
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for(i = 1; i < *gridColSize; i++)//第零行的最小路径和
        dp[0][i] = dp[0][i-1] + grid[0][i];
    for(i = 1;i < gridSize; i++)
        for(j = 1; j < *gridColSize; j++)
            dp[i][j] = (dp[i-1][j]<dp[i][j-1]?dp[i-1][j]:dp[i][j-1]) + grid[i][j];//动态方程
    return dp[gridSize-1][*gridColSize-1];
}
