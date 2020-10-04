class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        s.push("main");
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if (s.size() == 1)
                    continue;
                else
                    s.pop();
            }
            else if (logs[i] == "./") {
                continue;
            }
            else {
                string t = logs[i].substr(0,logs[i].size() - 1);
                s.push(t);
            }
        }
        return s.size() - 1;
    }
};
