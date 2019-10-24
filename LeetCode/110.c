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

int maxDepth(struct TreeNode* root){//���������������
    if(root == NULL)
        return 0;
    int depth_left = maxDepth(root -> left);
    int depth_right = maxDepth(root -> right);
    return depth_left>depth_right?depth_left+1:depth_right+1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL)//�����������ʱ
        return true;
    if(abs(maxDepth(root -> left) - maxDepth(root -> right)) <= 1)//�߶�ƽ�������������
        if(isBalanced(root -> left) == true && isBalanced(root -> right) == true)//ÿ���ڵ㶼Ҫ��������
            return true;
        else
            return false;
    else
        return false;
    return true;
}
