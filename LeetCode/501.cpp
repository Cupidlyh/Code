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
    int pre;//记录前一个结点的值
    int pre_num;//前一个节点的数量
    int max_num;//最大相同节点数量
    vector<int> ans;//结果

    //中序遍历
    void inorder(TreeNode* r) {
        if (r == NULL)
            return ;
        inorder(r -> left);
        if (r -> val == pre) {
            pre_num++;
        }
        else {
            if (max_num == 0) {
                max_num = pre_num;
                ans.push_back(pre);
            }
            else {
                if (max_num == pre_num) {
                    ans.push_back(pre);
                }
                else if (max_num < pre_num) {
                    ans.clear();
                    ans.push_back(pre);
                    max_num = pre_num;
                }
            }
            pre = r -> val;
            pre_num = 1;
        }
        inorder(r -> right);
        return ;
    }

    //找寻树的最左结点的值
    void left_num(TreeNode* r) {
        if (r == NULL)
            return ;
        pre = r -> val;
        left_num(r -> left);
        return ;
    }

    //BST树的中序遍历就是升序排列，用此性质来比较节点的值并找出结果
    vector<int> findMode(TreeNode* root) {
        if (root == NULL)
            return {};
        left_num(root);
        pre_num = 0;
        max_num = 0;
        inorder(root);
        if (max_num == pre_num) {
            ans.push_back(pre);
        }
        else if (max_num < pre_num) {
            ans.clear();
            ans.push_back(pre);
        }
        return ans;
    }
};
