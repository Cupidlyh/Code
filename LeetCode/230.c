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

static int arr[100000],j;//全局变量

void inorder(struct TreeNode* t){//树的中序遍历
    if(t){
        inorder(t->left);
        arr[j++]=t->val;//将元素存进数组中
        inorder(t->right);
    }
}

int kthSmallest(struct TreeNode* root, int k){
    j=1;
    memset(arr,0,sizeof(arr));//数组初始化
    inorder(root);//中序遍历
    return arr[k];//返回第k小的元素
}
