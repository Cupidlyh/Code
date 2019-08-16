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

struct TreeNode* invertTree(struct TreeNode* root){
    if(root==NULL)
       return NULL;
    struct TreeNode *temp=root->left;//交换树的左右指针的指向
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);//递归
    invertTree(root->right);//递归
    return root;
}
