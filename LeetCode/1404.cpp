class Solution {
public:
    bool ion(string s) {//判断当前二进制数是否为1
        string temp = "";
        for(int i = 0; i < s.size() - 1; i++)
            temp += "0";
        temp += "1";
        if(temp == s)
            return false;
        return true;
    }

    int numSteps(string s) {
        int i,res = 0;
        while(ion(s)) {
            res++;
            string snew = "0";//防止奇数加1运算时的进位
            if(s.at(s.size() - 1) == '0') {//偶数
                s = snew + s.substr(0,s.size() - 1);//二进制右移一位代表除2
            }
            else {//奇数
                snew += s;
                int bit = 1;//进位
                for(i = snew.size() - 1; i >= 0; i--) {//进行加1运算
                    if(bit == 0)
                        break;
                    else {
                        if(snew.at(i) == '0') {
                            bit = 0;
                            snew.at(i) = '1';
                        }
                        else {
                            snew.at(i) = '0';
                        }
                    }
                }
                if(snew.at(0) == '0')
                    s = snew.substr(1);
                else
                    s = snew;
            }
        }
        return res;
    }
};
