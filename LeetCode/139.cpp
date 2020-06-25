class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0 || s.length() == 0)
            return false;
        unordered_set<string> t;//���wordDict�г��ֵĵ���
        unordered_set<int> m;
        vector<int> v;//��¼���ʵĳ���
        for(int i = 0; i < wordDict.size(); i++) {
            t.insert(wordDict[i]);
            if(m.find(wordDict[i].length()) == m.end()) {
                v.push_back(wordDict[i].length());
                m.insert(wordDict[i].length());
            }
        }
        sort(v.begin(),v.end());//��С��������
        vector<int> dp(s.length(),0);
        if(t.find(s.substr(0,1)) != t.end())//�ж�s������ĸ�Ƿ�Ϊ�ֵ��еĵ���
            dp[0] = 1;
        //�ж�0λ�õ�iλ�õ��ַ����Ƿ�������ֵ��еĵ������
        for(int i = 1; i < s.length(); i++) {
            for(int j = 0; j < v.size(); j++) {
                if(i + 1 == v[j]) {//0λ�õ�iλ���Ƿ�����ֵ��еĵ���
                    if(t.find(s.substr(i - v[j] + 1,v[j])) != t.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
                if(i - v[j] < 0) {//���Ȳ����жϵ�ֱ����������Ϊv�����С���������ˣ�
                    break;
                }
                //�����ֵ䲻ͬ���ȵĵ���
                if(dp[i - v[j]] && t.find(s.substr(i - v[j] + 1,v[j])) != t.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.length() - 1];
    }
};
