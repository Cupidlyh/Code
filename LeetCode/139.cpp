class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0 || s.length() == 0)
            return false;
        unordered_set<string> t;//标记wordDict中出现的单词
        unordered_set<int> m;
        vector<int> v;//记录单词的长度
        for(int i = 0; i < wordDict.size(); i++) {
            t.insert(wordDict[i]);
            if(m.find(wordDict[i].length()) == m.end()) {
                v.push_back(wordDict[i].length());
                m.insert(wordDict[i].length());
            }
        }
        sort(v.begin(),v.end());//从小到大排序
        vector<int> dp(s.length(),0);
        if(t.find(s.substr(0,1)) != t.end())//判断s的首字母是否为字典中的单词
            dp[0] = 1;
        //判断0位置到i位置的字符串是否可以由字典中的单词组成
        for(int i = 1; i < s.length(); i++) {
            for(int j = 0; j < v.size(); j++) {
                if(i + 1 == v[j]) {//0位置到i位置是否就是字典中的单词
                    if(t.find(s.substr(i - v[j] + 1,v[j])) != t.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
                if(i - v[j] < 0) {//长度不够判断的直接跳出（因为v数组从小到大排序了）
                    break;
                }
                //尝试字典不同长度的单词
                if(dp[i - v[j]] && t.find(s.substr(i - v[j] + 1,v[j])) != t.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.length() - 1];
    }
};
