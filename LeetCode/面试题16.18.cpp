class Solution {
public:
    bool patternMatching(string pattern, string value) {
        //分情况讨论
        //1.pattern为空
        if(pattern.empty())
            return value.empty();
        //2.pattern不为空
        //2.1，value为空，判断pattern是否只有一个字母组成
        if(value.empty()) {
            int i;
            for(i = 1; i < pattern.length(); i++) {
                if(pattern[0] != pattern[i])
                    return false;
            }
            if(i == pattern.length())
                return true;
        }
        //2.2pattern不为空，value不为空
        int a = 0,b = 0;//存储pattern中a和b的数量
        for(int i = 0; i < pattern.length(); i++) {
            if(pattern[i] == 'a')
                a++;
            else
                b++;
        }
        //判断pattern中只出现一种字母的情况
        if(a == 0)//只出现b
            return check1(value,b);
        if(b == 0)//只出现a
            return check1(value,a);
        //2.2.1 a，b都出现，但可以其中一个为空字符串
        if(check1(value,a))//b为空串时
            return true;
        if(check1(value,b))//a为空串时
            return true;
        //2.2.2 a，b都不为空，枚举a，b长度，枚举a的长度就能唯一的确定b的长度
        for(int lena = 1; lena * a <= value.length() - b; lena++) {//b的长度至少为1，此为限定条件
            if((value.length() - lena * a) % b != 0)
                continue;
            int lenb = (value.length() - lena * a) / b;
            if(check2(pattern,value,lena,lenb))
                return true;
        }
        return false;
    }

    bool check1(string& value,int& k) {//判断value字符串能否正好分k段
        if(value.length() % k != 0)
            return false;
        int cnt = value.length() / k;
        for(int i = cnt; i < value.length(); i += cnt) {
            if(value.substr(i,cnt) != value.substr(0,cnt))//每段的字符串需相同
                return false;
        }
        return true;
    }

    bool check2(string& pattern,string& value,int& lena,int& lenb) {//按照a和b匹配的字符串的长度进行分割并进行判断
        string sa = "",sb = "";//代表a，b对应的字符串
        for(int i = 0,j = 0; i < pattern.length(); i++) {//i指针是指pattern的下标，j指针是指value的下标
            if(pattern[i] == 'a') {
                if(sa == "") {//空串时需要赋值
                    sa = value.substr(j,lena);
                }
                else {//比较
                    if(sa != value.substr(j,lena))
                        return false;
                }
                j += lena;
            }
            else {
                if(sb == "") {//空串时需要赋值
                    sb = value.substr(j,lenb);
                }
                else {//比较
                    if(sb != value.substr(j,lenb))
                        return false;
                }
                j += lenb;
            }
        }
        return sa != sb;//a，b所匹配的字符串不能相同
    }
};
