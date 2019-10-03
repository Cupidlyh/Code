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

int MAX(int a,int b) {
    if(a>b)
        return a;
    else
        return b;
}

int maxsum;

int max(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int left_max = MAX(max(root->left),0);//计算节点左子树的最大路径和
    int right_max = MAX(max(root->right),0);//计算节点右子树的最大路径和
    int now_max = root->val + left_max + right_max;//计算当前节点的最大路径和
    maxsum = MAX(maxsum,now_max);//在目前的最大值和当前节点的最大路径和二者中选取一个最大值
    return root->val + MAX(left_max,right_max);
}

int maxPathSum(struct TreeNode* root){
    maxsum = INT_MIN;
    max(root);
    return maxsum;
}
