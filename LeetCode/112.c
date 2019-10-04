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

int sumpath;//计算路径总和

bool Pathsummation(struct TreeNode* root, int sum) {
    sumpath = sumpath + root->val;//总路径的和加上当前传入的节点值
    if(root->left == NULL && root->right == NULL && sumpath == sum)//满足条件时，说明找到了一个路径满足题意
        return true;//返回为真
    if(root->left == NULL && root->right == NULL && sumpath != sum){//不满足条件时
        sumpath = sumpath - root->val;//因为返回到上一级程序接着运行，所以要总路径的和减去当前传入的节点值
        return false;//返回为假
    }
    if(root->left != NULL)//当前节点有左孩子时
        if(Pathsummation(root->left,sum) == true)
            return true;
    if(root->right != NULL)//当前节点有右孩子时
        if(Pathsummation(root->right,sum) == true)
            return true;
    sumpath = sumpath - root->val;//如果发现节点的右孩子遍历完，需要继续回退到上一级
    return false;
}

bool hasPathSum(struct TreeNode* root, int sum){
    sumpath=0;
    if(root == NULL)//当给定的树无任何节点时
        return false;
     return Pathsummation(root,sum);
}
