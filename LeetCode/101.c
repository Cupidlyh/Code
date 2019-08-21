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

bool iss(struct TreeNode *left,struct TreeNode *right){
    if(left==NULL||right==NULL)
        if(right==NULL&&left==NULL)
            return true;
        else
            return false;
    if(right!=NULL&&left!=NULL)
        if(right->val==left->val){
            if(iss(left->left,right->right)==false)//�ݹ�
                return false;
            if(iss(left->right,right->left)==false)//�ݹ�
                return false;
        }
        else
            return false;
    return true;
}

bool isSymmetric(struct TreeNode* root){
    if(root!=NULL)
        if(iss(root->left,root->right)==false)
            return false;
    return true;
}
