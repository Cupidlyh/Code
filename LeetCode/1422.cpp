class Solution {
public:
    int maxScore(string s) {
        int zero = 0,one = 0;//��¼0��1������
        int ze[505] = {0},on[505] = {0};//��¼s[i]���0���������Ҳ�1������
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
        for(i = 0; i < s.length() - 1; i++)//ȡ���ĵ÷�
            max = max < (ze[i] + on[i]) ? (ze[i] + on[i]) : max;
        return max;
    }
};
