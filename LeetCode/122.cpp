class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        //相邻两天买卖能获得利润的都加到一起去
        for(int i = 1; i < prices.size(); i++)
            if(prices[i] > prices[i - 1])
                res += prices[i] - prices[i - 1];
        return res;
    }
};
