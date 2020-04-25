class Solution {
public:
    int dp[1000005];

    int waysToChange(int n) {
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int i,j,arr[4] = {25,10,5,1};
        //第一层for循环决定了每次由哪些硬币组成钱数
        //一开始只有25，再一次是25,10，再一次是25,10,5，再一次是25,10,5,1（这样可以保证没有重复的）
        for(i = 0; i < 4; i++) {
            int temp = arr[i];
            for(j = temp; j <= n; j++)
                dp[j] = (dp[j] + dp[j - temp]) % 1000000007;
        }
        return dp[n];
    }
};
