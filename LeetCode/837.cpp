class Solution {
public:
    double new21Game(int N, int K, int W) {
        double sum = 0,i;
        vector<double> dp(K + W,0);
        //dp[x]Ϊ����������Ϊxʱ���ܻ�ʤ�ĸ����ǣ�dp[x]=1/w * (dp[x+1]+dp[x+2]+dp[x+3]...+dp[x+w])
        //��ʤ������С�ڵ���N�����������ڵ���K��ֹͣ����
        //����������Ϊ���ڵ���K��С�ڵ���Nʱ����ʤ���ʶ�Ϊ1
        for (i = K; i < K + W && i <= N; i++) {
            dp[i] = 1.0;
            sum += dp[i];
        }
        //��ʽ�ӿ��Կ��������ǿ��ԴӺ���ǰ��̬�滮
        for(i = K - 1; i >= 0; i--) {
            dp[i] = sum / W;//��ֵ
            sum = sum - dp[i + W] + dp[i];//��ȥĩβ�ģ��������ڵģ�ά����W��֮�ͣ�
        }
        return dp[0];
    }
};
