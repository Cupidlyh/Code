class Solution {
public:
    //原串：                   1 1 1 1  1  1
    //1的序号：                1 2 3 4  5  6
    //到当前1位置组成的1子串： 1 3 6 10 15 21
    //1=0+1  3=1+2  6=3+3……21=15+6
    //规律就是当前1的数量加上前一个连续1位置的组成子串的数量
    int numSub(string s) {
        //num_1记录连续1串中1的数量（中间出现0断了就重新记录）
        //now记录的是到当前1的位置组成的全由1组成的字符串
        int res = 0,num_1 = 0,now = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                num_1 = (num_1 + 1) % 1000000007;
                now = (now + num_1) % 1000000007;
            }
            else {
                res = (res + now) % 1000000007;
                num_1 = 0;
                now = 0;
            }
        }
        res = (res + now) % 1000000007;
        return res;
    }
};
