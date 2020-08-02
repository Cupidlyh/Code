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
    //采用先序遍历，根左右
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return ;
        //保留当前节点右子树
        TreeNode* oldRight = root -> right;
        //把当前节点左子树放到原来右子树的位置
        root -> right = root -> left;
        //左子树置空
        root -> left = nullptr;
        //找到原先左子树的最右节点
        TreeNode* rightNode = root;
        while(rightNode -> right != nullptr)
            rightNode = rightNode -> right;
        //将原先的左子树接到rightNode的右子树上
        rightNode -> right = oldRight;
        //按照先序遍历的次序，递归调用左右子树，但是左子树已经指向nullptr，因此可省去
        //flatten(root->left);
        flatten(root -> right);
    }
};
