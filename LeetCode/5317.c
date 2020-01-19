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


struct TreeNode* removeLeafNodes(struct TreeNode* root, int target){
    if(root -> left)
        root -> left = removeLeafNodes(root -> left,target);
    if(root -> right)
        root -> right = removeLeafNodes(root -> right,target);
    if(root -> val == target) {
        if(root -> left == NULL && root -> right == NULL) {
            return NULL;
        }
    }
    return root;
}


