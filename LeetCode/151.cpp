class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int len = s.length(),left,right;
        for(left = 0; left < len; left++)//去掉首部空格
            if(s[left] != ' ')
                break;
        int num = 0;//记录单词数
        int i = len;
        while(i >= left)
        {
            for(i = i - 1; i >= left; i--)//去空格
                if(s[i] != ' ')
                    break;
            right = i;//right记录当前这个单词的尾部
            for(; i >= left; i--)//找单词的长度（当前单词的头部）
                if(s[i] == ' ')
                    break;
            if(num == 0) {//首个进去的单词前面不需要空格
                num++;
                ans += s.substr(i + 1,right - i);//截取单词加到结果中
            }
            else {//第二个单词开始前面要加空格隔开
                ans += " ";
                ans += s.substr(i + 1,right - i);//截取单词加到结果中
            }
        }
        return ans;
    }
};
