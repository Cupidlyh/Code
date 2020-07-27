class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2,vector<int>(n + 2,0));
        //����һ���������飬������β�����1�����㴦��߽����
        vector<int> temp(n + 2);
        temp[0] = 1;
        temp[n + 1] = 1;
        for(int i = 1; i <= n; i++)
            temp[i] = nums[i - 1];
         //len��ʾ�����䳤�ȣ���ÿһ�����䳤�Ƚ���ѭ����
        for(int len = 3; len <= n + 2; len++) {
            //l��ʾ��������˵�,l + len - 1���ʾ�������Ҷ˵�
            for(int l = 0; l <= n + 2 - len; l++) {
                //kΪ�������ڵ������������������һ�������Ƶ�����
                for(int k = l + 1; k < l + len - 1; k++) {
                    int left = dp[l][k];
                    int right = dp[k][l + len - 1];
                    int sum = left + right + temp[k] * temp[l] * temp[l + len - 1];
                    dp[l][l + len - 1] = max(dp[l][l + len - 1],sum);//ȡ������ֵ
                }
            }
        }
        return dp[0][n + 1];
    }
};
