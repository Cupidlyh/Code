class Solution {
    unordered_set<int> dayset;
    vector<int> costs;
    int money[366] = {0};//�����i�쵽���һ�컨�ѵ�Ǯ��
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this -> costs = costs;
        for(int i = 0; i < days.size(); i++)
            dayset.insert(days[i]);
        memset(money,-1,sizeof(money));
        return dp(0);
    }

    int dp(int i) {
        if(i > 365)//����365���ѿ϶���0Ԫ
            return 0;
        if(money[i] != -1)
            return money[i];
        if(dayset.count(i))//��i����days�����У�ѡȡ���ֻ�����С��
            money[i] = min(min(dp(i + 1) + costs[0],dp(i + 7) + costs[1]),dp(i + 30) + costs[2]);
        else//��i�첻��days�����У��Ͳ�����Ʊ�����Ե��ں�һ���Ǯ��
            money[i] = dp(i + 1);
        return money[i];
    }
};
