class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string> m = {//��ϣ��
            {"&quot;","\""},
            {"&apos;","'"},
            {"&amp;","&"},
            {"&gt;",">"},
            {"&lt;","<"},
            {"&frasl;","/"}
        };
        int i,two = 0;//two��¼ͷ���Ƿ���˫����
        if(text[0] == '"')
            two = 1;
        string ans = "";//����ַ���
        for(i = 0; i < text.length(); i++) {
            if(text[i] == '&') {//�����ַ���ʼ�ַ�
                int flag = 0;//flag����Ƿ��������ַ�
                unordered_map<string,string>::iterator it;//������
                if(text.length() - i >= 7) {
                    it = m.find(text.substr(i,7));
                    if(it != m.end()) {
                        ans += m[text.substr(i,7)];
                        i = i + 7 - 1;//�±����������ַ���
                        flag = 1;
                    }
                }
                if(text.length() - i >= 6) {
                    it = m.find(text.substr(i,6));
                    if(it != m.end()) {
                        if(m[text.substr(i,6)] == "\"" && two == 1) {
                            ans += "\\";
                            ans += m[text.substr(i,6)];
                            i = i + 6 - 1;
                            flag = 1;
                        }
                        else{
                            ans += m[text.substr(i,6)];
                            i = i + 6 - 1;
                            flag = 1;
                        }
                    }
                }
                if(text.length() - i >= 5) {
                    it = m.find(text.substr(i,5));
                    if(it != m.end()) {
                        ans += m[text.substr(i,5)];
                        i = i + 5 - 1;
                        flag = 1;
                    }
                }
                if(text.length() - i >= 4) {
                    it = m.find(text.substr(i,4));
                    if(it != m.end()) {
                        ans += m[text.substr(i,4)];
                        i = i + 4 - 1;
                        flag = 1;
                    }
                }
                if(flag == 0)
                    ans += text[i];
            }
            else
                ans += text[i];
        }
        return ans;
    }
};
