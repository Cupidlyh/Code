class Solution {
public:
    unordered_map <char, int> tt,ss;

    bool check() {//判断子串中是否包含T中所有字母
        for (auto p:tt) {
            if (ss[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        for(int i = 0; i < t.length(); i++)
            tt[t[i]]++;
        int left = 0,right = -1;
        int ansl = -1,len = INT_MAX;
        //滑动窗口，如果窗口内子串不包含T中所有字母，那么右指针一直向右（扩大窗口）
        //如果遍历到子串包含T中所有字母，那么左指针向右（缩小窗口），缩小的过程就是为了找最小子串，重复这两步
        while(right < int(s.length())) {
            right++;
            ss[s[right]]++;
            while(check() && left <= right) {
                if(len > right - left + 1) {
                    ansl = left;
                    len = right - left + 1;
                }
                ss[s[left]]--;
                left++;
            }
        }
        return ansl == -1 ? "" : s.substr(ansl,len);
    }
};
