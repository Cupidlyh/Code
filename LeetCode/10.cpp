class Solution {
public:
    //sb表示s的下标，pb表示p的下标
    bool match(string& s,int sb,string& p,int pb) {
        if(pb >= p.length())//正则串超出长度判断待匹配字符串是否也超出长度
            return sb >= s.length();
        bool curr = sb < s.length() && ((s[sb] == p[pb]) || (p[pb] == '.'));//判断当前下标是否可以匹配
        if(pb + 1 < p.length() && p[pb + 1] == '*') {//'*' 匹配零个或多个前面的那一个元素
            //匹配0个正则串需要下标移动两位，待匹配字符串下标不移动（因为可以以匹配零个所以当前元素判断是否可以对应是无所谓的）
            //匹配多个正则串下标不移动，待匹配字符串下标移动一位
            return match(s,sb,p,pb + 2) || (curr && match(s,sb + 1,p,pb));
        }
        else {//没遇到'.'或'*'继续判断二者的下一个下标
            return curr && match(s,sb + 1,p,pb + 1);
        }
    }

    bool isMatch(string s, string p) {
        return match(s,0,p,0);
    }
};
