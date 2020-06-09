class Solution {
public:
    int translateNum(int num) {
        if(num == 0)
            return 1;
        int numm[12],dp[12];//numm存储每一位的数字，dp[i]表示数字第i位（包含i）之前翻译数
        int bit = log10(num) + 1;//计算num的位数
        int i = bit - 1;
        while(num) {
            numm[i--] = num % 10;
            num /= 10;
        }
        dp[0] = 1;//一位数肯定是可以翻译成一种
        //之后便进行动态规划，当前数字和前一位数字组成的数字是否大于25
        //大于25，dp[i] = dp[i-1]，小于等于25，dp[i] = dp[i-1]+dp[i-2];
        if(bit >= 2 && numm[0] * 10 + numm[1] <= 25)
            dp[1] = 2;
        else
            dp[1] = 1;
        for(i = 2; i <= bit - 1; i++) {
            if(numm[i - 1] != 0 && numm[i - 1] * 10 + numm[i] <= 25)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[bit - 1];
    }
};
