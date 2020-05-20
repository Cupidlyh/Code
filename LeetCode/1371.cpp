class Solution {
public:
    int findTheLongestSubstring(string s) {
        int len = s.length(),res = 0,status = 0;
        vector<int>pos(1<<5,-1);//存储的是字符串的长度
        pos[0] = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] ==  'a')
                status ^= 1<<0;
            if(s[i] ==  'e')
                status ^= 1<<1;
            if(s[i] ==  'i')
                status ^= 1<<2;
            if(s[i] ==  'o')
                status ^= 1<<3;
            if(s[i] ==  'u')
                status ^= 1<<4;
            if(pos[status] != -1)
                res = max(res,i + 1 - pos[status]);
            else
                pos[status] = i + 1;
        }
        return res;
    }
};
