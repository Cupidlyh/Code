class node {
public:
    int torf = -1;//代表此单词的下标
    node *next[26] = {nullptr};//每个节点有26个指针代表26个字母
};

class Trie {
public:
    node *root;//树的根节点
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word,int id) {//将单词插入到前缀树中
        node * temp = root;
        for(int i = 0; i < word.length(); i++) {
            if(temp -> next[word[i] - 'a'] == nullptr) {
                node * t = new node();
                temp -> next[word[i] - 'a'] = t;
                temp = t;
            }
            else
                temp = temp -> next[word[i] - 'a'];
        }
        temp -> torf = id;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    //判断字典树中是否存在单词prefix并返回单词下标
    int startsWith(string prefix) {
        node * temp = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(temp -> next[prefix[i] - 'a'] != nullptr) {
                temp = temp -> next[prefix[i] - 'a'];
            }
            else
                return -1;
        }
        return temp -> torf;
    }
};

class Solution {
public:
    //判断s串的[left,right]部分是不是回文串
     bool isPalindrome(string& s, int left, int right) {
        int len = right - left + 1;
        for (int i = 0; i < len / 2; i++) {
            if (s[left + i] != s[right - i]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        //创建字典树
        Trie* trie = new Trie();
        int n = words.size();
        //将单词插入字典树中
        for (int i = 0; i < n; i++)
            trie -> insert(words[i],i);
        vector<vector<int>> res;
        //枚举每个单词的所有前缀和后缀并判断是否为回文串
        //如果是回文串，我们就查询其剩余部分的翻转是否在给定的字符串序列中出现即可。
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            for (int j = 0; j <= m; j++) {
                //前缀
                if (j && isPalindrome(words[i], 0, j - 1)) {
                    //翻转剩余部分
                    string temp = words[i].substr(j,m - j);
                    reverse(temp.begin(),temp.end());
                    //判断翻转后的剩余部分是否出现在单词集合words中
                    int right_id = trie -> startsWith(temp);
                    if (right_id != -1 && right_id != i) {
                        res.push_back({right_id, i});
                    }
                }
                //后缀
                if (isPalindrome(words[i], j, m - 1)) {
                    //翻转剩余部分
                    string temp = words[i].substr(0,j);
                    reverse(temp.begin(),temp.end());
                    //判断翻转后的剩余部分是否出现在单词集合words中
                    int left_id = trie -> startsWith(temp);
                    if (left_id != -1 && left_id != i) {
                        res.push_back({i, left_id});
                    }
                }
            }
        }
        return res;
    }
};
