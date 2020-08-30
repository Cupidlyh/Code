class Solution {
public:
    string reverseWords(string s) {
        int i = 0,j = 0;
        //将每个单词进行反转
        while (i < s.size()) {
            if(s[i] == ' ') {
                int k = i - 1;
                while(j < k) {
                    swap(s[j],s[k]);
                    j++;
                    k--;
                }
                j = i + 1;
            }
            i++;
        }
        int k = i - 1;
        while(j < k) {
            swap(s[j],s[k]);
            j++;
            k--;
        }
        return s;
    }
};
