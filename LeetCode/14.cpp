class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string res = "";
        int i = 0;
        //����ɨ�裺���±�0��ʼ���ж�ÿһ���ַ������±�0���ж��Ƿ�ȫ����ͬ��ֱ��������ȫ����ͬ���±ꡣ
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
