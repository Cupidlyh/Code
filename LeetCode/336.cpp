class node {
public:
    int torf = -1;//����˵��ʵ��±�
    node *next[26] = {nullptr};//ÿ���ڵ���26��ָ�����26����ĸ
};

class Trie {
public:
    node *root;//���ĸ��ڵ�
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word,int id) {//�����ʲ��뵽ǰ׺����
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
    //�ж��ֵ������Ƿ���ڵ���prefix�����ص����±�
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
    //�ж�s����[left,right]�����ǲ��ǻ��Ĵ�
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
        //�����ֵ���
        Trie* trie = new Trie();
        int n = words.size();
        //�����ʲ����ֵ�����
        for (int i = 0; i < n; i++)
            trie -> insert(words[i],i);
        vector<vector<int>> res;
        //ö��ÿ�����ʵ�����ǰ׺�ͺ�׺���ж��Ƿ�Ϊ���Ĵ�
        //����ǻ��Ĵ������ǾͲ�ѯ��ʣ�ಿ�ֵķ�ת�Ƿ��ڸ������ַ��������г��ּ��ɡ�
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            for (int j = 0; j <= m; j++) {
                //ǰ׺
                if (j && isPalindrome(words[i], 0, j - 1)) {
                    //��תʣ�ಿ��
                    string temp = words[i].substr(j,m - j);
                    reverse(temp.begin(),temp.end());
                    //�жϷ�ת���ʣ�ಿ���Ƿ�����ڵ��ʼ���words��
                    int right_id = trie -> startsWith(temp);
                    if (right_id != -1 && right_id != i) {
                        res.push_back({right_id, i});
                    }
                }
                //��׺
                if (isPalindrome(words[i], j, m - 1)) {
                    //��תʣ�ಿ��
                    string temp = words[i].substr(0,j);
                    reverse(temp.begin(),temp.end());
                    //�жϷ�ת���ʣ�ಿ���Ƿ�����ڵ��ʼ���words��
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
