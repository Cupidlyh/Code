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

    int deep(struct TreeNode* root) {//ͨ���ݹ�����������������
    if(root == NULL)
        return 0;
    int left = deep(root -> left) + 1;
    int right = deep(root -> right) + 1;
    return max(left,right);
}

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int temp = deep(root -> left) + deep(root -> right);//���㵱ǰ�ڵ�����ֱ��
        maxl = maxl > temp ? maxl : temp;//����֪��ֱ���Ƚ�ȡ���ֵ
        diameterOfBinaryTree(root -> left);//�ݹ������������ֱ��
        diameterOfBinaryTree(root -> right);//�ݹ������������ֱ��
        return maxl;
    }
};
