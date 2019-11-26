package leetcode63;

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int row = obstacleGrid.length;//��Ŀ�����Ķ�ά���������
        int col = obstacleGrid[0].length;//��Ŀ�����Ķ�ά���������
        int[][] dp = new int[row][col];
        int i,j;
        for(i = 0; i < row; i++)//������ֻ��һ��·�����Ե���
            if(obstacleGrid[i][0] == 0)//��λ��ʱ
                dp[i][0] = 1;
            else//�������ϰ�����ô֮���·�����޷�����
                break;
        for(i = 0; i < col; i++)//������ֻ��һ��·�����Ե���
            if(obstacleGrid[0][i] == 0)//��λ��ʱ
                dp[0][i] = 1;
            else//�������ϰ�����ô֮���·�����޷�����
                break;
        for(i = 1; i < row; i++)//������Ŀ�����Ķ�ά����
            for(j = 1; j < col; j++) {
                if(obstacleGrid[i][j] == 1)//�����ϰ��������
                    continue;
                //��Ϊֻ�������߻��������ߣ����Ե��ﵱǰλ�õ�·��ֻ�д��ϱ߹�������߹�������
                //Ȼ�����ж�һ���������Ƿ����ϰ���Ϳ�����
                if(obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j-1] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];//��̬����
                if(obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j-1] != 0)
                    dp[i][j] = dp[i-1][j];
                if(obstacleGrid[i - 1][j] != 0 && obstacleGrid[i][j-1] == 0)
                    dp[i][j] = dp[i][j-1];
            }
        return dp[row-1][col-1];
    }
}