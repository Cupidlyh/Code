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

    //二叉搜索树的中序遍历结果就是从小到大排列
    //所以我们只需要倒着遍历（右根左）然后累加节点值就可以。
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
