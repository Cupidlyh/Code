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

int max(int a,int b) {//比较大小
    if(a > b)
        return a;
    else
        return b;
}

int rob(struct TreeNode* root){
    if(root == NULL)
            return 0;
    //分别表示左孩子，左孩子的左孩子，左孩子的右孩子，右孩子，右孩子的右孩子，右孩子的左孩子
    int left = 0,leftl = 0,leftr = 0,right = 0,rightr = 0,rightl = 0;
    left = rob(root -> left);//递归计算左孩子的最大值
    right = rob(root -> right);//递归计算右孩子的最大值
    if(root -> left) {//如果左孩子存在
        leftl = rob(root -> left -> left);//递归算出左孩子的左孩子的最大值
        leftr = rob(root -> left -> right);//递归算出左孩子的右孩子的最大值
    }
    if(root -> right) {//如果右孩子存在
        rightl = rob(root -> right -> left);//递归算出右孩子的左孩子的最大值
        rightr = rob(root -> right -> right);//递归算出右孩子的右孩子的最大值
    }
    //在偷取当前根节点和不偷取当前根节点这两种情况中选一个较大的
    return max(left + right,root -> val + leftl + leftr + rightl + rightr);
}
