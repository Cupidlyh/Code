class node {
    public:
    bool torf = false;//代表此单词是否插入成功
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
    void insert(string word) {//将单词插入到前缀树中
        node * temp = root;
        for(int i = word.length() - 1; i >= 0; i--) {
            if(temp -> next[word[i] - 'a'] == nullptr) {
                node * t = new node();
                temp -> next[word[i] - 'a'] = t;
                temp = t;
            }
            else
                temp = temp -> next[word[i] - 'a'];
        }
        temp -> torf = true; 
    }
};
//以上为前缀树的实现

class Solution {
public:
    int res = 0;

    void leaflen(node *t,int len) {//通过递归来计算出所有从根节点到叶子节点的路径长度总和
        int flag = 0,i;
        for(i = 0; i < 26; i++) {
            if(t -> next[i] != nullptr) {
                flag = 1;
                leaflen(t -> next[i],len + 1);
            }
        }
        if(flag == 0) {
            res += len;
            return ;
        }
    }

    int minimumLengthEncoding(vector<string>& words) {
        Trie* obj = new Trie();//前缀树
        for(string s : words) {//将单词插入进前缀树中
            obj -> insert(s);
        }
        leaflen(obj -> root,1);
        return res;
    }
};