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
    if(root==NULL||root->left==NULL)//���ص�����
        return ;
    root->left->next=root->right;//ͬһ������ߵĽڵ�ָ���ұߵĽڵ�
    if(root->next!=NULL)//���������ұߵĽڵ�ʱ
        root->right->next=root->next->left;//ĳ�����ڵ���ҽڵ�ָ��˸��ұ����ڸ�����ڵ�
    next(root->left);//�ݹ�������
    next(root->right);//�ݹ�������
    return ;
}

class Solution {
public:
    Node* connect(Node* root) {
        next(root);
        return root;
    }
};
