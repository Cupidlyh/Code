class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int i,j;
        for(i = 0; i < words.size(); i++) {//�����ַ��������ж�word[i]�ǲ���word[j]���Ӵ�
            for(j = 0; j < words.size(); j++) {
                if(i == j)//�����Լ�����
                    continue;
                if(words[i].length() > words[j].length())//�Ӵ�����ҪС��ԭ��
                    continue;
                int loc = words[j].find(words[i],0);
                if(loc != string::npos) {//���word[i]��word[j]���Ӵ�
                    ans.push_back(words[i]);//�浽�����
                    break;
                }
            }
        }
        return ans;
    }
};
