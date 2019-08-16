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

void preorder(struct TreeNode* t){//先序遍历
    if(t){
        arr[n++]=t->val;
        preorder(t->left);//递归
        preorder(t->right);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    n=0;//n用来记录数组中元素的数量
    memset(arr,0,sizeof(arr));//数组初始化
    preorder(root);
    *returnSize=n;
    return arr;
}
