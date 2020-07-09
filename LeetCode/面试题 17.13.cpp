class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> len;//��¼�ֵ������е��ʵĳ���
        unordered_set<int> l;//����ֵ��е��ʵĳ���
        unordered_set<string> s;//����ֵ��г��ֵĵ���
        for(int i = 0; i < dictionary.size(); i++) {
            s.insert(dictionary[i]);
            if(l.find(dictionary[i].length()) == l.end()) {
                len.push_back(dictionary[i].length());
                l.insert(dictionary[i].length());
            }
        }
        sort(len.begin(),len.end());//��С��������
        vector<int> dp(sentence.length() + 1,0);
        //����dp��dp[i]����ǰi���ַ�[0,i)������δʶ���ַ�
        for(int i = 1; i <= sentence.length(); i++) {
            //�ȼ��赱ǰ��ĸ��ǰ�����ĸ�޷�����ֵ��еĵ���
            dp[i] = dp[i - 1] + 1;//δʶ���ַ���1
            //��ǰ��ĸ�ܷ��ǰ����ַ�����ֵ��еĵ���
            for(int j = 0; j < len.size(); j++) {
                if(len[j] > i)
                    break;
                //����ֵ��еĵ��ʵ����
                if(s.find(sentence.substr(i - len[j],len[j])) != s.end()) {
                    dp[i] = min(dp[i],dp[i - len[j]]);//ȡ��Сֵ
                }
            }
        }
        return dp[sentence.length()];
    }
};
