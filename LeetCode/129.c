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

int sum,k;

void Pathsummation(struct TreeNode* root,int *temp) {
    temp[k] = root->val;//当前节点的值存入临时数组中
    k = k + 1;
    if(root->left == NULL && root->right == NULL) {//当找到从根到叶子节点的路径
        int i=0,j;
        for(j = k-1;j >= 0;j--)
            sum = sum + temp[j]*pow(10,i++);//计算所有的根到叶子节点的数字之和
        k = k - 1;
        return ;
    }
    if(root->left != NULL)//当前节点有左孩子时
        Pathsummation(root->left,temp);
    if(root->right != NULL)//当前节点有右孩子时
        Pathsummation(root->right,temp);
    k = k - 1;
    return ;
}

int sumNumbers(struct TreeNode* root){
    if(root == NULL)
        return 0;
    sum = 0;
    k = 0;
    int temp[1000] = {0};
    Pathsummation(root,temp);
    return sum;
}
