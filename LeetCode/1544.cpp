class Solution {
public:
    string makeGood(string s) {
        //利用栈来进行相邻字符串的判断
        //其实比较的就是相邻的字符是不是相反的大小写字符
        stack<char> t;
        for(int i = 0; i < s.size(); i++) {
            //栈为空直接压入字符
            if(t.empty()) {
                t.push(s[i]);
            }
            else {
                //判断相邻的字符是不是相反的大小写字符，是就弹出，不是就压入
                if(t.top() - 32 == s[i] || t.top() + 32 == s[i])
                    t.pop();
                else
                    t.push(s[i]);
            }
        }
        //将栈中字符转化成结果
        string res = "";
        while(!t.empty()) {
            res += t.top();
            t.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
