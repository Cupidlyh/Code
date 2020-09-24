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
    int pre;//��¼ǰһ������ֵ
    int pre_num;//ǰһ���ڵ������
    int max_num;//�����ͬ�ڵ�����
    vector<int> ans;//���

    //�������
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

    //��Ѱ�����������ֵ
    void left_num(TreeNode* r) {
        if (r == NULL)
            return ;
        pre = r -> val;
        left_num(r -> left);
        return ;
    }

    //BST����������������������У��ô��������ȽϽڵ��ֵ���ҳ����
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
