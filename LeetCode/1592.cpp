class Solution {
public:
    string reorderSpaces(string text) {
        string temp = "";
        //�洢����
        vector<string> t;
        //��¼�ո���
        int num = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                num++;
                if (temp != "") {
                    t.push_back(temp);
                    temp = "";
                }
            }
            else {
                temp += text[i];
            }
        }
        if (temp != "") {
            t.push_back(temp);
        }
        //��¼ÿ�����ʼ�Ŀո���
        int num1 = 0;
        if (t.size() - 1 > 0)
            num1 = num / (t.size() - 1);
        //��¼����ո���
        int num2 = num - num1 * (t.size() - 1);
        string res = "";
        for (int i = 0; i < t.size() - 1; i++) {
            res += t[i];
            for (int j = 0; j < num1; j++) {
                res += ' ';
            }
        }
        res += t[t.size() - 1];
        for (int i = 0; i < num2; i++) {
            res += " ";
        }
        return res;
    }
};
