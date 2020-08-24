class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        //Ã¶¾Ù×Ó´®
        for(int i = 1; i * 2 <= n; i++) {
            if(n % i == 0) {
                int temp = 1;
                for(int j = i; j < n; j++) {
                    if(s[j] != s[j - i]) {
                        temp = 0;
                        break;
                    }
                }
                if(temp)
                    return true;
            }
        }
        return false;
    }
};
