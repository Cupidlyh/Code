class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";//存储结果
        //加法运算是从两个数字的尾部开始相加
        int i = num1.length() - 1;//num1的尾部
        int j = num2.length() - 1;//num2的尾部
        int carry = 0;//进位
        while(i >= 0 || j >= 0) {
            //存储num1,num2当前位的数字
            int num11 = 0,num22 = 0;
            if(i >= 0) {
                num11 = num1[i--] - '0';
            }
            if(j >= 0) {
                num22 = num2[j--] - '0';
            }
            int sum = 0;
            //记录当前位的和
            sum = (num11 + num22 + carry) % 10;
            res += sum + '0';//将和加到结果中
            //计算进位
            carry = (num11 + num22 + carry) / 10;
        }
        //如果还有进位信息，加到结果中
        if(carry != 0)
            res += carry + '0';
        //翻转字符串即为num1 + num2的结果
        reverse(res.begin(), res.end());
        return res;
    }
};
