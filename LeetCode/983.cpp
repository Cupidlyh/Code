class Solution {
    unordered_set<int> dayset;
    vector<int> costs;
    int money[366] = {0};//代表第i天到最后一天花费的钱数
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this -> costs = costs;
        for(int i = 0; i < days.size(); i++)
            dayset.insert(days[i]);
        memset(money,-1,sizeof(money));
        return dp(0);
    }

    int dp(int i) {
        if(i > 365)//超过365花费肯定是0元
            return 0;
        if(money[i] != -1)
            return money[i];
        if(dayset.count(i))//第i天在days数组中，选取三种花费最小的
            money[i] = min(min(dp(i + 1) + costs[0],dp(i + 7) + costs[1]),dp(i + 30) + costs[2]);
        else//第i天不在days数组中，就不用买票，所以等于后一天的钱数
            money[i] = dp(i + 1);
        return money[i];
    }
};
