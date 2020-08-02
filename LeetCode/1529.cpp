class Solution {
public:
    int minFlips(string target) {
        //比较相邻字符是否相同，不同就计数加一。另外首位的字母也要判断是否为'1'（要进行额外的翻转）
        int step = 0;
        if(target[0] == '1')
            step++;
        for(int i = 1; i < target.length(); i++) {
            if(target[i] != target[i - 1])
                step++;
        }
        return step;
    }
};
