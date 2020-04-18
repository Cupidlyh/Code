class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int i,j;
        for(i = 0; i < words.size(); i++) {//遍历字符串数组判断word[i]是不是word[j]的子串
            for(j = 0; j < words.size(); j++) {
                if(i == j)//跳过自己本身
                    continue;
                if(words[i].length() > words[j].length())//子串长度要小于原串
                    continue;
                int loc = words[j].find(words[i],0);
                if(loc != string::npos) {//如果word[i]是word[j]的子串
                    ans.push_back(words[i]);//存到结果中
                    break;
                }
            }
        }
        return ans;
    }
};
