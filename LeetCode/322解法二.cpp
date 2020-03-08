#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i]��ʾ�ճɽ��Ϊi��Ǯ��Ҫ������Ӳ����
        vector<int>dp(amount + 1, amount + 1);//���ٴ�СΪamount+1�����鲢����ֵΪamount+1
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {//��ʾ��ǰҪ�յý��
            for(int j = 0; j < coins.size(); j++) {//��֪Ӳ�ҵĽ��
                if(coins[j] <= i)//2��Ǯ�ܲ�����5�����հɣ��������������
                    dp[i] = min(dp[i],dp[i - coins[j]] + 1);//״̬����
            }
        }
        //�ճ�10��Ǯ���ʹ��10��һ��ǮӲ�ң�����������ڱ����˾�Ҫ����-1������ղ���
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
