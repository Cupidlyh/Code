class Solution {
public:
    string longestPrefix(string s) {
        vector<int> next(s.length(),-1);
        int k = -1,i;
        /*
            next[i]表示关于字符串s的子串 s[0..i] 最长的既是前缀也是后缀的字符串(允许前后缀在原字符串中重叠)
            但这个字符串不能是 s[0..i] 本身。例如当字符串为 s = abacaba 时，
            aba 就是最长的既是前缀也是后缀的字符串，next[6] 的值为 2（注意字符串的下标是从 0 开始的）
            s 的前缀 s[0..2] 和后缀 s[4..6] 均为 aba。
        */
        for(i = 1; i < s.length(); i++)//就是KMP算法中预处理的那部分函数
        {
            while(k > -1 && s[k + 1] != s[i])
                k = next[k];
            if(s[k + 1] == s[i])
                k++;
            next[i] = k;
        }
        return s.substr(0,next[s.length() - 1] + 1);
    }
};
