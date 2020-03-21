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

void inorder(struct TreeNode* t){//中序遍历
    if(t){
        inorder(t->left);
        arr[n++]=t->val;
        inorder(t->right);
    }
}

struct TreeNode* ToBST(int left,int right) {//利用递归重新建立平衡二叉搜索树
    if(left > right)
        return NULL;
    int mid = (left + right) / 2;//二分中值
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
	root->left = ToBST(left,mid-1);//注意mid-1 对左半部分进行递归
	root->right = ToBST(mid+1,right);//注意mid+1 对右半部分进行递归
	return root;
}

struct TreeNode* balanceBST(struct TreeNode* root){
    n = 0;
    inorder(root);
    return ToBST(0,n-1);
}
