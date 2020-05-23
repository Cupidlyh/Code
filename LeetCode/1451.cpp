class Solution {
public:
    string arrangeWords(string text) {
        vector<string>str;//存储text中的单词
        //arr记录长度为i的单词是否存在，map标记str中的单词是否存到了结果中
        int arr[205] = {0},map[100005] = {0};
        int len = 0,i,j;
        string s = "";
        for(i = 0; i < text.length(); i++) {//将text中的单词存到str中
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
        for(i = 0; i < 205; i++) {//按单词长度和顺序将单词存到结果中
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
        if(res[0] >= 'a' && res[0] <= 'z')//第一个单词首字母要大写
            res[0] = res[0] - 32;
        return res.substr(0,res.length() - 1);//去掉最后一个空格
    }
};
