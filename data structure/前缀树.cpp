#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


class node {
public:
    bool torf = false;//代表此单词是否插入成功
    node *next[26] = {nullptr};//每个节点有26个指针代表26个字母(不同问题可以开不同大小的数组)
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
        for(int i = 0; i < word.length(); i++) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {//判断此前缀树中是否包含此单词
        node * temp = root;
        for(int i = 0; i < word.length(); i++) {
            if(temp -> next[word[i] - 'a'] != nullptr) {
                temp = temp -> next[word[i] - 'a'];
            }
            else
                return false;
        }
        return temp -> torf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {//判断是否有单词以某个字符串开头
        node * temp = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(temp -> next[prefix[i] - 'a'] != nullptr) {
                temp = temp -> next[prefix[i] - 'a'];
            }
            else
                return false;
        }
        return true;
    }

    //不同的问题还可以写其他的一些函数
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
