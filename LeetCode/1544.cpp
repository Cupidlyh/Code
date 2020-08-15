class Solution {
public:
    string makeGood(string s) {
        //����ջ�����������ַ������ж�
        //��ʵ�Ƚϵľ������ڵ��ַ��ǲ����෴�Ĵ�Сд�ַ�
        stack<char> t;
        for(int i = 0; i < s.size(); i++) {
            //ջΪ��ֱ��ѹ���ַ�
            if(t.empty()) {
                t.push(s[i]);
            }
            else {
                //�ж����ڵ��ַ��ǲ����෴�Ĵ�Сд�ַ����Ǿ͵��������Ǿ�ѹ��
                if(t.top() - 32 == s[i] || t.top() + 32 == s[i])
                    t.pop();
                else
                    t.push(s[i]);
            }
        }
        //��ջ���ַ�ת���ɽ��
        string res = "";
        while(!t.empty()) {
            res += t.top();
            t.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
