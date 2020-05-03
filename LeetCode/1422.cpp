class Solution {
public:
    int maxScore(string s) {
        int zero = 0,one = 0;//记录0和1的数量
        int ze[505] = {0},on[505] = {0};//记录s[i]左侧0的数量和右侧1的数量
        int i,max = 0;
        for(i = 0; i < s.length(); i++)
            if(s[i] == '1')
                one++;
        for(i = 0; i < s.length() - 1; i++) {
            if(s[i] == '0') {
                zero++;
                ze[i] = zero;
                on[i] = one;
            }
            if(s[i] == '1') {
                one--;
                ze[i] = zero;
                on[i] = one;
            }
        }
        for(i = 0; i < s.length() - 1; i++)//取最大的得分
            max = max < (ze[i] + on[i]) ? (ze[i] + on[i]) : max;
        return max;
    }
};
