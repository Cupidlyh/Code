#include <iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

void next(Node *root) {
    if(root==NULL||root->left==NULL)//返回的条件
        return ;
    root->left->next=root->right;//同一个根左边的节点指向右边的节点
    if(root->next!=NULL)//当不是最右边的节点时
        root->right->next=root->next->left;//某个根节点的右节点指向此根右边相邻根的左节点
    next(root->left);//递归左子树
    next(root->right);//递归右子树
    return ;
}

class Solution {
public:
    Node* connect(Node* root) {
        next(root);
        return root;
    }
};
