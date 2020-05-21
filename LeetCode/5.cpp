class Solution {
public:
    //计算以left和right为中心向外扩展的回文串长度
    int function(string s,int left,int right) {
        int l = left,r = right;
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }


    string longestPalindrome(string s) {
        int start = 0,end = 0,len;
        for(int i = 0; i < s.length(); i++) {
            int len1 = function(s,i,i);//中心为一个字母的情况(回文串长度为奇数，如aba)
            int len2 = function(s,i,i + 1);//中心为两个字母的情况(回文串长度为偶数，如abba)
            len = max(len1,len2);//选择长的
            if(len > end - start) {//更新始末坐标
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start,end - start + 1);//截取回文串并返回
    }
};
