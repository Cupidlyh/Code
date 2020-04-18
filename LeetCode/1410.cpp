class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string> m = {//哈希表
            {"&quot;","\""},
            {"&apos;","'"},
            {"&amp;","&"},
            {"&gt;",">"},
            {"&lt;","<"},
            {"&frasl;","/"}
        };
        int i,two = 0;//two记录头部是否有双引号
        if(text[0] == '"')
            two = 1;
        string ans = "";//结果字符串
        for(i = 0; i < text.length(); i++) {
            if(text[i] == '&') {//特殊字符起始字符
                int flag = 0;//flag标记是否有特殊字符
                unordered_map<string,string>::iterator it;//迭代器
                if(text.length() - i >= 7) {
                    it = m.find(text.substr(i,7));
                    if(it != m.end()) {
                        ans += m[text.substr(i,7)];
                        i = i + 7 - 1;//下标跳到特殊字符后
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
