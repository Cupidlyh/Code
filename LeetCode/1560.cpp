class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        //num记录每个扇区经过的次数,sta是每个阶段的起点,end是每个阶段的终点
        int num[105] = {0};
        int sta,end;
        //模拟跑马拉松的过程，并记录每个扇区经过的次数
        sta = rounds[0];
        end = rounds[1];
        if(end < sta) {
            for(int j = sta; j <= n; j++)
                num[j]++;
            for(int j = 1; j <= end; j++)
                num[j]++;
        }
        else {
            for(int j = sta; j <= end; j++)
                num[j]++;
        }
        for(int i = 1; i < rounds.size() - 1; i++) {
            sta = rounds[i] + 1;
            end = rounds[i + 1];
            if(end < sta) {
                for(int j = sta; j <= n; j++)
                    num[j]++;
                for(int j = 1; j <= end; j++)
                    num[j]++;
            }
            else {
                for(int j = sta; j <= end; j++)
                    num[j]++;
            }
        }
        //找出扇区中的经过次数最大值
        int maxx = 0;
        for(int i = 1; i <= n; i++)
            maxx = max(maxx,num[i]);
        vector<int>res;
        //将经过次数等于最大值的存到结果中
        for(int i = 1; i <= n; i++)
            if(num[i] == maxx)
                res.push_back(i);
        return res;
    }
};
