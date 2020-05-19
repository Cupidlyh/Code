class Solution {
public:
    bool check_s(int low,int high,string s) {
        while(low <= high && low < s.length() && high >= 0) {//判断是否是回文串
            if(s[low] == s[high]) {
                low++;
                high--;
            }
            else {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0,right = s.length() - 1;
        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                //只能删除一个字符，所以判断删除左边的或删除右边的字符能不能成为回文串
                return check_s(left + 1,right,s) || check_s(left,right - 1,s);
            }
        }
        return true;
    }
};
