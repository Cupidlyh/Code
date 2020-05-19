class Solution {
public:
    bool check_s(int low,int high,string s) {
        while(low <= high && low < s.length() && high >= 0) {//�ж��Ƿ��ǻ��Ĵ�
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
                //ֻ��ɾ��һ���ַ��������ж�ɾ����ߵĻ�ɾ���ұߵ��ַ��ܲ��ܳ�Ϊ���Ĵ�
                return check_s(left + 1,right,s) || check_s(left,right - 1,s);
            }
        }
        return true;
    }
};
