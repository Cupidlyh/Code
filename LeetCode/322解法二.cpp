#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i]表示凑成金额为i的钱需要的最少硬币数
        vector<int>dp(amount + 1, amount + 1);//开辟大小为amount+1的数组并赋初值为amount+1
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {//表示当前要凑得金额
            for(int j = 0; j < coins.size(); j++) {//已知硬币的金额
                if(coins[j] <= i)//2块钱总不能用5块来凑吧，所以有这个条件
                    dp[i] = min(dp[i],dp[i - coins[j]] + 1);//状态方程
            }
        }
        //凑成10块钱最多使用10个一块钱硬币，所以如果大于本身了就要返回-1，代表凑不出
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
