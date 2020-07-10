class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(),vector<int>(3,0));
        dp[0][0] = -prices[0];
        //����Ĵ����䶳��ָ�����ڵ� ii�����֮���״̬��Ҳ����˵������� ii�����֮�����䶳�ڣ���ô�� i+1 ���޷������Ʊ��
        // dp[i][0]: ���ϳ��й�Ʊ���������
        // dp[i][1]: ���ϲ����й�Ʊ�����Ҵ����䶳���е��ۼ��������
        // dp[i][2]: ���ϲ����й�Ʊ�����Ҳ����䶳���е��ۼ��������
        for(int i = 1; i < prices.size(); i++) {
             dp[i][0] = max(dp[i - 1][0],dp[i - 1][2] - prices[i]);
             dp[i][1] = dp[i - 1][0] + prices[i];
             dp[i][2] = max(dp[i - 1][1],dp[i - 1][2]);
        }
        return max(dp[prices.size() - 1][1],dp[prices.size() - 1][2]);
    }
};
