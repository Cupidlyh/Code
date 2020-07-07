class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> left;
        //先加入-1是为了避免一开始是左括号时，没有最后一个没被匹配的右括号的下标
        left.push(-1);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {//遇见左括号
                left.push(i);//下标存入栈中
            }
            else {//遇见右括号
                left.pop();//弹出左括号代表匹配了右括号
                if(left.empty()) {//栈为空
                    left.push(i);//加入下标代表最后一个没被匹配的右括号的下标
                    continue;
                }
                //栈不为空，当前右括号的下标减去栈顶元素即为以该右括号为结尾的最长有效括号的长度
                res = max(res,i - left.top());
            }
        }
        return res;
    }
};
