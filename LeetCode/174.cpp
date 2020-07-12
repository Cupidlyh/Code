class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        //dp[i][j] ��ʾ������ (i,j) ���յ��������С��ʼֵ��
        //���仰˵�������ǵ������� (i,j) ʱ�������ʱ���ǵ�·���Ͳ�С��dp[i][j]�����Ǿ��ܵ����յ�
        dp[n - 1][m - 1] =  max(1 - dungeon[n - 1][m - 1],1);
        for(int j = m - 2; j >= 0; --j) {//���һ���ȳ�ʼ��
            dp[n - 1][j] = max(dp[n - 1][j + 1] - dungeon[n - 1][j],1);
        }
        for(int i = n - 2; i >= 0; --i) {//���һ���ȳ�ʼ��
            dp[i][m - 1] = max(dp[i + 1][m - 1] - dungeon[i][m - 1],1);
        }
        //�����µ����Ͻ��ж�̬�滮
        for(int i = n - 2; i >= 0; --i) {
            for(int j = m - 2; j >= 0; --j) {
                int minn = min(dp[i][j + 1],dp[i + 1][j]);
                dp[i][j] = max(minn - dungeon[i][j],1);
            }
        }
        return dp[0][0];
    }
};
