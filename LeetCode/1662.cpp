class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word11 = "";
        string word22 = "";
        for (int i = 0; i < word1.size(); i++) {
            word11 += word1[i];
        }
        for (int i = 0; i < word2.size(); i++) {
            word22 += word2[i];
        }
        if (word11 == word22)
            return true;
        return false;
    }
};
