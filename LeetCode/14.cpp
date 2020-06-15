class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string res = "";
        int i = 0;
        //纵向扫描：从下标0开始，判断每一个字符串的下标0，判断是否全部相同。直到遇到不全部相同的下标。
        while(true) {
            char ch;
            if(i < strs[0].size()) {
                ch = strs[0][i];
            }
            else
                break;
            bool flag = false;
            for(int j = 1; j < strs.size(); j++) {
                if(strs[j].size() <= i) {
                    flag = true;
                    break;
                }
                if(strs[j][i] != strs[0][i]) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            res += ch;
            i++;
        }
        return res;
    }
};
