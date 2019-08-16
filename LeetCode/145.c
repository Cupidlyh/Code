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

void postorder(struct TreeNode* t){//后序遍历
    if(t){
        postorder(t->left);//递归
        postorder(t->right);
        arr[n++]=t->val;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    n=0;//n用来记录数组中元素的数量
    memset(arr,0,sizeof(arr));//数组初始化
    postorder(root);
    *returnSize=n;
    return arr;
}
