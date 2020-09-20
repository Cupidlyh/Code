class Solution {
public:
    //С����
    struct cmp {
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //��¼Ԫ�س��ִ���
        unordered_map<int,int> num;
        for (int i = 0; i < nums.size(); i++) {
            num[nums[i]]++;
        }
        //����С�������Ƚϳ�������Ƶ��ǰk�ߵ�Ԫ��
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
        for (unordered_map<int,int>::iterator it = num.begin(); it != num.end(); it++) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }
        //��Ϊ��С�������Ե��Ŵ洢
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = que.top().first;
            que.pop();
        }
        return res;
    }
};
