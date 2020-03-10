#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxl = 0;

    int deep(struct TreeNode* root) {//通过递归计算二叉树的最大深度
    if(root == NULL)
        return 0;
    int left = deep(root -> left) + 1;
    int right = deep(root -> right) + 1;
    return max(left,right);
}

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int temp = deep(root -> left) + deep(root -> right);//计算当前节点的最大直径
        maxl = maxl > temp ? maxl : temp;//与已知的直径比较取最大值
        diameterOfBinaryTree(root -> left);//递归计算左子树的直径
        diameterOfBinaryTree(root -> right);//递归计算右子树的直径
        return maxl;
    }
};
