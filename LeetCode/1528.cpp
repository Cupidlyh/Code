class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> ch(s.length());//字符数组存储字符串s
        for(int i = 0; i < s.length(); i++) {//移动到指定位置
            ch[indices[i]] = s[i];
        }
        //再将字符数组转成字符串
        string res = "";
        for(int i = 0; i < ch.size(); i++)
            res += ch[i];
        return res;
    }
};
