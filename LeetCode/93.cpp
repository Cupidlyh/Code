class Solution {
public:
    int num(string s) {//将字符串转成数字
        int ans = 0;
        int bit = 1;
        for(int i = s.size() - 1; i >= 0; i--) {
            ans += (s[i] - '0') * bit;
            bit *= 10;
        }
        return ans;
    }

    //通过递归来复原IP地址
    //temp记录中间结果的，sbit是记录串s遍历到下标，ipbit是当前要建立的IP段
    void dfs(string s,string temp,int sbit,int ipbit,vector<string>& res) {
        //如果剩下的字符串不够剩下的IP段分配（每个IP段至少占用以一位字符（个数））
        if(s.size() - sbit < 4 - ipbit + 1)
            return ;
        //题目的IP由四段组成
        if(ipbit > 4) {
            //字符串s在建立前四段IP时正好用完
            if(sbit == s.size())//加入结果中
                res.push_back(temp.substr(0,temp.size() - 1));
            return ;
        }
        //因为整数范围为0-255，i代表的是数字的位数
        for(int i = 1; i <= 3; i++) {
            string s1 = "";
            if(sbit + i <= s.size()) {
                s1 = s.substr(sbit,i);
                //数字前面不能有前导零
                if(s1[0] == '0' && s1.size() != 1)
                    break;
                int num1 = num(s1);
                if(num1 > 255)
                    break;
            }
            //递归
            dfs(s,temp + s1 + ".",sbit + i,ipbit + 1,res);
        }
        return ;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size() > 12 || s.size() < 4)
            return res;
        dfs(s,"",0,1,res);
        return res;
    }
};
