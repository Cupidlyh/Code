class Solution {
public:
    string reformat(string s) {
        int n1 = 0,n2 = 0,i,j;//n1记录数字数量,n2记录字母数量
        char number[500] = {'0'},letter[500] = {'0'};
        int len = s.length();
        for(i = 0; i < len; i++) {
            if(s[i] >= '0' && s[i] <= '9')
                number[n1++] = s[i];
            if(s[i] >= 'a' && s[i] <= 'z')
                letter[n2++] = s[i];
        }
        if(abs(n2 - n1) > 1)//差值大于1就无法重新格式化
            return "";
        string ans = "";
        i = 0;
        j = 0;
        if(n1 - n2 == 0) {
            while(i < n1 && j < n2) {
                ans += letter[j++];
                ans += number[i++];
            }
        }
        else {//字母和数字哪个多一个就用它开头
            if(n1 > n2) {
                ans += number[i++];
                while(i < n1 && j < n2) {
                    ans += letter[j++];
                    ans += number[i++];
                }
            }
            else {
                ans += letter[j++];
                while(i < n1 && j < n2) {
                    ans += number[i++];
                    ans += letter[j++];
                }
            }
        }
        return ans;
    }
};
