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

int maxDepth(struct TreeNode* root){//求二叉树的最大深度
    if(root == NULL)
        return 0;
    int depth_left = maxDepth(root -> left);
    int depth_right = maxDepth(root -> right);
    return depth_left>depth_right?depth_left+1:depth_right+1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL)//当空树的情况时
        return true;
    if(abs(maxDepth(root -> left) - maxDepth(root -> right)) <= 1)//高度平衡二叉树的条件
        if(isBalanced(root -> left) == true && isBalanced(root -> right) == true)//每个节点都要满足条件
            return true;
        else
            return false;
    else
        return false;
    return true;
}
