class Solution {
public:
    //��ĿҪ���invert����
    void invert(string& s) {
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
    }

    char findKthBit(int n, int k) {
        if(n == 1)
            return '0';
        string temp = "0";
        string res = "";
        //���Sn�ַ���
        for(int i = 2; i <= n; i++) {
            res = temp + "1";
            invert(temp);
            reverse(temp.begin(),temp.end());
            res += temp;
            temp = res;
            res = "";
        }
        //����Sn��k���ַ�
        return temp[k - 1];
    }
};
