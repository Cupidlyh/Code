class Solution {
public:
    //此map是为了记录字符串防止重复出现
    unordered_map<string,int> mp;
    int len;
    int res;

    //利用回溯来遍历出所有情况
    void search(string& s,int bit,int num) {
        if (bit >= len) {
            res = max(res,num);
            return ;
        }

        //剪枝
        if (len - bit + num <= res) {
            return ;
        }

        //i为从字符串s的bit位置开始截取的长度
        for (int i = 1; i <= len - bit; i++) {
            string temp = s.substr(bit,i);
            if (mp.find(temp) == mp.end() || mp[temp] == 0) {
                mp[temp] = 1;
                search(s,bit + i,num + 1);
                mp[temp] = 0;
            }
        }
        return ;
    }

    int maxUniqueSplit(string s) {
        len = s.size();
        res = -1;
        search(s,0,0);
        return res;
    }
};
