class Solution {
public:
    //������left��rightΪ����������չ�Ļ��Ĵ�����
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
            int len1 = function(s,i,i);//����Ϊһ����ĸ�����(���Ĵ�����Ϊ��������aba)
            int len2 = function(s,i,i + 1);//����Ϊ������ĸ�����(���Ĵ�����Ϊż������abba)
            len = max(len1,len2);//ѡ�񳤵�
            if(len > end - start) {//����ʼĩ����
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start,end - start + 1);//��ȡ���Ĵ�������
    }
};
