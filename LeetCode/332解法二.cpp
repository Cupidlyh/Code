class Solution {
public:
    int n;
    unordered_map<string,queue<string>> m;
    vector<string> res;

    bool dfs(string curr) {
        if(res.size() == n + 1)
            return true;
        if(m[curr].size() == 0)
            return false;
        int size = m[curr].size();
        int currsize = 0;
        while (m[curr].size() > 0 && m.find(curr) != m.end() && currsize < size) {
            currsize++;
            string temp = m[curr].front();
            m[curr].pop();
            res.push_back(temp);
            if(dfs(temp))
                return true;
            else {
                res.pop_back();
                m[curr].push(temp);
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        unordered_map<string,priority_queue<string, vector<string>, greater<string>>> m1;
        for (int i = 0; i < n; i++) {
            m1[tickets[i][0]].push(tickets[i][1]);
        }
        for (auto q : m1) {
            string s = q.first;
            while (m1[s].size()) {
                m[s].push(m1[s].top());
                m1[s].pop();
            }
        }
        res.push_back("JFK");
        dfs("JFK");
        return res;
    }
};