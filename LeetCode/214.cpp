class Solution {
public:
    //���next����
    //next[i] + 1��ʾ�ַ���s�������ǰ��׺
    void pre_next(string& s,vector<int>& next) {
        int k = -1;
        for (int i = 1; i < s.size(); i++) {
             while (k > -1 && s[k + 1] != s[i])
                k = next[k];
             if (s[k + 1] == s[i])
                k++;
            next[i] = k;
        }
    }

    string shortestPalindrome(string s) {
        string res = "";
        string rev_s = s;
        reverse(rev_s.begin(),rev_s.end());
        string new_s = s + '#' + rev_s;
        vector<int> next(new_s.size(),-1);
        pre_next(new_s,next);
        //���������s�������ǰ׺��Ȼ����rev_s�ĺ�׺�п������ǰ׺���ټӵ�sǰ�档
        res = rev_s.substr(0,rev_s.size() - (next[new_s.size() - 1] + 1)) + s;
        return res;
    }
};
