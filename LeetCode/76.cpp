class Solution {
public:
    unordered_map <char, int> tt,ss;

    bool check() {//�ж��Ӵ����Ƿ����T��������ĸ
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
        //�������ڣ�����������Ӵ�������T��������ĸ����ô��ָ��һֱ���ң����󴰿ڣ�
        //����������Ӵ�����T��������ĸ����ô��ָ�����ң���С���ڣ�����С�Ĺ��̾���Ϊ������С�Ӵ����ظ�������
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
