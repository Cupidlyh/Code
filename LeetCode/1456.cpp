class Solution {
public:
    int maxVowels(string s, int k) {
        int maxx = 0,num = 0,i,arr[100005] = {0};
        for(i = 0; i < s.length(); i++) {//统计[0,i]区间内的元音字母数量
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    num++;
            arr[i] = num;
        }
        for(i = 0; i <= s.length() - k; i++) {
            //计算[i,i + k - 1]区间内元音字母数量并取最大值
            if(i == 0)
                num = arr[i + k - 1];
            else
                num = arr[i + k - 1] - arr[i - 1];
            maxx = maxx > num ? maxx : num;
        }
        return maxx;
    }
};
