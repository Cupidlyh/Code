class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> ch(s.length());//�ַ�����洢�ַ���s
        for(int i = 0; i < s.length(); i++) {//�ƶ���ָ��λ��
            ch[indices[i]] = s[i];
        }
        //�ٽ��ַ�����ת���ַ���
        string res = "";
        for(int i = 0; i < ch.size(); i++)
            res += ch[i];
        return res;
    }
};
