class Solution {
public:
    string arrangeWords(string text) {
        vector<string>str;//�洢text�еĵ���
        //arr��¼����Ϊi�ĵ����Ƿ���ڣ�map���str�еĵ����Ƿ�浽�˽����
        int arr[205] = {0},map[100005] = {0};
        int len = 0,i,j;
        string s = "";
        for(i = 0; i < text.length(); i++) {//��text�еĵ��ʴ浽str��
            if(text[i] == ' ') {
                str.push_back(s);
                arr[len]++;
                s = "";
                len = 0;
            }
            else {
                len++;
                if(text[i] >= 'A' && text[i] <= 'Z')
                    s += text[i] + 32;
                else
                    s += text[i];
            }
        }
        str.push_back(s);
        arr[len]++;
        string res = "";
        for(i = 0; i < 205; i++) {//�����ʳ��Ⱥ�˳�򽫵��ʴ浽�����
            if(arr[i] != 0) {
                for(j = 0; j < str.size(); j++) {
                    if(map[j] == 0 && str[j].length() == i) {
                        map[j] = 1;
                        res += str[j];
                        res += ' ';
                    }
                }
            }
        }
        if(res[0] >= 'a' && res[0] <= 'z')//��һ����������ĸҪ��д
            res[0] = res[0] - 32;
        return res.substr(0,res.length() - 1);//ȥ�����һ���ո�
    }
};
