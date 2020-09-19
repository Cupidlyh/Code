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

    //lr记录此时的p节点是它父节点的哪颗子树，0左子树，1右子树，-1根节点
    void traverseTree(TreeNode* p,int lr) {
        if (p == NULL)
            return ;
        if (lr == 0) {
            if (p -> left == NULL && p -> right == NULL)
                sum += p -> val;
        }
        traverseTree(p -> left,0);
        traverseTree(p -> right,1);
        return ;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        traverseTree(root,-1);
        return sum;
    }
};
