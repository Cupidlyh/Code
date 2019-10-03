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
    int left_max = MAX(max(root->left),0);//����ڵ������������·����
    int right_max = MAX(max(root->right),0);//����ڵ������������·����
    int now_max = root->val + left_max + right_max;//���㵱ǰ�ڵ�����·����
    maxsum = MAX(maxsum,now_max);//��Ŀǰ�����ֵ�͵�ǰ�ڵ�����·���Ͷ�����ѡȡһ�����ֵ
    return root->val + MAX(left_max,right_max);
}

int maxPathSum(struct TreeNode* root){
    maxsum = INT_MIN;
    max(root);
    return maxsum;
}
