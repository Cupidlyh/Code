#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int n,arr[10005];

void inorder(struct TreeNode* t){//�������
    if(t){
        inorder(t->left);
        arr[n++]=t->val;
        inorder(t->right);
    }
}

struct TreeNode* ToBST(int left,int right) {//���õݹ����½���ƽ�����������
    if(left > right)
        return NULL;
    int mid = (left + right) / 2;//������ֵ
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
	root->left = ToBST(left,mid-1);//ע��mid-1 ����벿�ֽ��еݹ�
	root->right = ToBST(mid+1,right);//ע��mid+1 ���Ұ벿�ֽ��еݹ�
	return root;
}

struct TreeNode* balanceBST(struct TreeNode* root){
    n = 0;
    inorder(root);
    return ToBST(0,n-1);
}
