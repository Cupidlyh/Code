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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static n,arr[5000];//全局变量

void inorder(struct TreeNode* t){//递归中序遍历
    if(t){
        inorder(t->left);
        arr[n++]=t->val;
        inorder(t->right);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    n=0;//n用来记录数组中元素的个数
    memset(arr,0,sizeof(arr));//数组的初始化
    inorder(root);
    *returnSize=n;
    return arr;
}
