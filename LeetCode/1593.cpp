class Solution {
public:
    //��map��Ϊ�˼�¼�ַ�����ֹ�ظ�����
    unordered_map<string,int> mp;
    int len;
    int res;

    //���û������������������
    void search(string& s,int bit,int num) {
        if (bit >= len) {
            res = max(res,num);
            return ;
        }

        //��֦
        if (len - bit + num <= res) {
            return ;
        }

        //iΪ���ַ���s��bitλ�ÿ�ʼ��ȡ�ĳ���
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
