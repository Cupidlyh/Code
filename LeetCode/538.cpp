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
    int sum = 0;

    //�������������������������Ǵ�С��������
    //��������ֻ��Ҫ���ű������Ҹ���Ȼ���ۼӽڵ�ֵ�Ϳ��ԡ�
    void traverse(TreeNode* root) {
        if (root == NULL)
            return ;
        traverse(root -> right);
        int temp = root -> val;
        root -> val += sum;
        sum += temp;
        traverse(root -> left);
        return;
    }

    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};
