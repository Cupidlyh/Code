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
    //树的前序遍历
    void preorder(TreeNode* t1, TreeNode* t2,TreeNode*& res) {
        int num1 = 0,num2 = 0;
        //记录是否有一个节点以上是非空节点
        int flag = 0;
        if (t1 != NULL) {
            flag = 1;
            num1 = t1 -> val;
        }
        if (t2 != NULL) {
            flag = 1;
            num2 = t2 -> val;
        }
        if (flag) {
            res -> val = num1 + num2;
        }
        if (!flag) {
            res = NULL;
        }
        //根据节点的空还是非空进行递归合并
        if (res) {
            res -> left = new TreeNode();
            res -> right = new TreeNode();
            if (t1 != NULL && t2 != NULL) {
                preorder(t1 -> left,t2 -> left,res -> left);
                preorder(t1 -> right,t2 -> right,res -> right);
            }
            else if (t1 == NULL && t2 != NULL) {
                preorder(NULL,t2 -> left,res -> left);
                preorder(NULL,t2 -> right,res -> right);
            }
            else if (t2 == NULL && t1 != NULL) {
                preorder(t1 -> left,NULL,res -> left);
                preorder(t1 -> right,NULL,res -> right);
            }
            else if (t1 == NULL && t2 == NULL) {
                preorder(NULL,NULL,res -> left);
                preorder(NULL,NULL,res -> right);
            }
        }
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* res = new TreeNode();
        preorder(t1,t2,res);
        return res;
    }
};
