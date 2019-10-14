#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n){
    int dp[m][n],i,j;//dp[i][j]�ǵ���i,j�����·��
    for(i = 0; i < m; i++)//������ֻ��һ��·�����Ե���
        dp[i][0] = 1;
    for(i = 0; i < n; i++)//������ֻ��һ��·�����Ե���
        dp[0][i] = 1;
    for(i = 1; i < m; i++)
        for(j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];//��̬����
    return dp[m-1][n-1];
}
