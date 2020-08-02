/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //�������������������
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return ;
        //������ǰ�ڵ�������
        TreeNode* oldRight = root -> right;
        //�ѵ�ǰ�ڵ��������ŵ�ԭ����������λ��
        root -> right = root -> left;
        //�������ÿ�
        root -> left = nullptr;
        //�ҵ�ԭ�������������ҽڵ�
        TreeNode* rightNode = root;
        while(rightNode -> right != nullptr)
            rightNode = rightNode -> right;
        //��ԭ�ȵ��������ӵ�rightNode����������
        rightNode -> right = oldRight;
        //������������Ĵ��򣬵ݹ�������������������������Ѿ�ָ��nullptr����˿�ʡȥ
        //flatten(root->left);
        flatten(root -> right);
    }
};
