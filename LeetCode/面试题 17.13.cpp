class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> len;//记录字典中所有单词的长度
        unordered_set<int> l;//标记字典中单词的长度
        unordered_set<string> s;//标记字典中出现的单词
        for(int i = 0; i < dictionary.size(); i++) {
            s.insert(dictionary[i]);
            if(l.find(dictionary[i].length()) == l.end()) {
                len.push_back(dictionary[i].length());
                l.insert(dictionary[i].length());
            }
        }
        sort(len.begin(),len.end());//从小到大排序
        vector<int> dp(sentence.length() + 1,0);
        //暴力dp，dp[i]代表前i个字符[0,i)中最少未识别字符
        for(int i = 1; i <= sentence.length(); i++) {
            //先假设当前字母和前面的字母无法组成字典中的单词
            dp[i] = dp[i - 1] + 1;//未识别字符加1
            //当前字母能否和前面的字符组成字典中的单词
            for(int j = 0; j < len.size(); j++) {
                if(len[j] > i)
                    break;
                //组成字典中的单词的情况
                if(s.find(sentence.substr(i - len[j],len[j])) != s.end()) {
                    dp[i] = min(dp[i],dp[i - len[j]]);//取最小值
                }
            }
        }
        return dp[sentence.length()];
    }
};
