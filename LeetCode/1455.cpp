class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>ss;
        int i,j = 0;
        for(i = 0; i < sentence.length(); i++) {//�Ƚ����е��ʴ浽ss��
            if(sentence[i] == ' ') {
                ss.push_back(sentence.substr(j, i - j));
                j = i + 1;
            }
        }
        ss.push_back(sentence.substr(j,i - j));
        for(i = 0; i < ss.size(); i++) {
            if(ss[i].substr(0,searchWord.length()) == searchWord)//�ж�ǰ׺
                return i + 1;
        }
        return -1;
    }
};
