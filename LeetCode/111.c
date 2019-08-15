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


int minDepth(struct TreeNode* root){
    if(root==NULL)
        return 0;
    int depth_left = minDepth(root->left);
    int depth_right = minDepth(root->right);
    if(depth_left==0||depth_right==0)
        return depth_left+depth_right+1;
    else
        return depth_left>depth_right?depth_right+1:depth_left+1;
}
