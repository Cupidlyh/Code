class Solution {
public:
    string longestPrefix(string s) {
        vector<int> next(s.length(),-1);
        int k = -1,i;
        /*
            next[i]��ʾ�����ַ���s���Ӵ� s[0..i] ��ļ���ǰ׺Ҳ�Ǻ�׺���ַ���(����ǰ��׺��ԭ�ַ������ص�)
            ������ַ��������� s[0..i] �������統�ַ���Ϊ s = abacaba ʱ��
            aba ������ļ���ǰ׺Ҳ�Ǻ�׺���ַ�����next[6] ��ֵΪ 2��ע���ַ������±��Ǵ� 0 ��ʼ�ģ�
            s ��ǰ׺ s[0..2] �ͺ�׺ s[4..6] ��Ϊ aba��
        */
        for(i = 1; i < s.length(); i++)//����KMP�㷨��Ԥ������ǲ��ֺ���
        {
            while(k > -1 && s[k + 1] != s[i])
                k = next[k];
            if(s[k + 1] == s[i])
                k++;
            next[i] = k;
        }
        return s.substr(0,next[s.length() - 1] + 1);
    }
};
