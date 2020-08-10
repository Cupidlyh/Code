class Solution {
public:
    /*思路就是统计记录连续的0，1数量，在分界点时取二者最小值加到结果中
    **然后根据之后的情况将0，1之中某个置为0重新进行计数
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
