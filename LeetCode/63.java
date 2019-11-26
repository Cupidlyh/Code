package leetcode63;

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int row = obstacleGrid.length;//题目所给的二维数组的行数
        int col = obstacleGrid[0].length;//题目所给的二维数组的列数
        int[][] dp = new int[row][col];
        int i,j;
        for(i = 0; i < row; i++)//第零列只有一条路径可以到达
            if(obstacleGrid[i][0] == 0)//空位置时
                dp[i][0] = 1;
            else//出现了障碍物那么之后的路径就无法到达
                break;
        for(i = 0; i < col; i++)//第零行只有一条路径可以到达
            if(obstacleGrid[0][i] == 0)//空位置时
                dp[0][i] = 1;
            else//出现了障碍物那么之后的路径就无法到达
                break;
        for(i = 1; i < row; i++)//遍历题目所给的二维数组
            for(j = 1; j < col; j++) {
                if(obstacleGrid[i][j] == 1)//遇到障碍物就跳过
                    continue;
                //因为只能向下走或者向右走，所以到达当前位置的路径只有从上边过来和左边过来两种
                //然后再判断一下这两种是否有障碍物就可以了
                if(obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j-1] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];//动态方程
                if(obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j-1] != 0)
                    dp[i][j] = dp[i-1][j];
                if(obstacleGrid[i - 1][j] != 0 && obstacleGrid[i][j-1] == 0)
                    dp[i][j] = dp[i][j-1];
            }
        return dp[row-1][col-1];
    }
}