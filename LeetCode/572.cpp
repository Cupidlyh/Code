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
    bool equal(TreeNode* s, TreeNode* t) {//�ж�s��ĳһ�������Ƿ��tһ��
        if(s == nullptr && t == nullptr)
            return true;
        if((s == nullptr && t != nullptr) || (s != nullptr && t == nullptr) || (s -> val != t -> val))
            return false;
        return equal(s -> left,t -> left) && equal(s -> right,t -> right);
    }

    bool dfs(TreeNode* s, TreeNode* t) {
        if(s == nullptr)
            return false;
        return equal(s,t) || dfs(s -> left,t) || dfs(s -> right,t);//�ݹ���в���
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s,t);
    }
};
