class Solution {
public:
    /*˼·����ͳ�Ƽ�¼������0��1�������ڷֽ��ʱȡ������Сֵ�ӵ������
    **Ȼ�����֮��������0��1֮��ĳ����Ϊ0���½��м���
    */
    int countBinarySubstrings(string s) {
        int res = 0;
        int zero = 0,one = 0;
        for(int i = 0; i < s.size(); i++) {
            if((s[i] == '1' && i < s.size() - 1 && s[i + 1] == '0') || s[i] == '1' && i == s.size() - 1) {
                one++;
                res += min(zero,one);
                zero = 0;
                continue;
            }
            if((s[i] == '0' && i < s.size() - 1 && s[i + 1] == '1') || s[i] == '0' && i == s.size() - 1) {
                zero++;
                res += min(zero,one);
                one = 0;
                continue;
            }
            if(s[i] == '1')
                one++;
            if(s[i] == '0')
                zero++;
        }
        return res;
    }
};
