class Solution {
public:
    //记录表的关系，并利用优先队列排序
    unordered_map<string,priority_queue<string, vector<string>, greater<string>>> m;
    vector<string> res;

    //深度优先搜索
    void dfs(string curr) {
        while (m[curr].size() > 0 && m.find(curr) != m.end()) {
            string temp = m[curr].top();
            m[curr].pop();
            dfs(temp);
        }
        res.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++) {
            m[tickets[i][0]].push(tickets[i][1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
