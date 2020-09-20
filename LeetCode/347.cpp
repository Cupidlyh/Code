class Solution {
public:
    //小顶堆
    struct cmp {
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //记录元素出现次数
        unordered_map<int,int> num;
        for (int i = 0; i < nums.size(); i++) {
            num[nums[i]]++;
        }
        //利用小顶堆来比较出来出现频率前k高的元素
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
        for (unordered_map<int,int>::iterator it = num.begin(); it != num.end(); it++) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }
        //因为是小顶堆所以倒着存储
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = que.top().first;
            que.pop();
        }
        return res;
    }
};
