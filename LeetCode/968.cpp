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
    int res;
    int postorder(TreeNode* root) {
        // �սڵ㣬�ýڵ��и���
        if (root == NULL)
            return 2;
        int left = postorder(root -> left);
        int right = postorder(root -> right);
        // ���1
        // ���ҽڵ㶼�и���
        if (left == 2 && right == 2)
            return 0;
         // ���2
        // left == 0 && right == 0 ���ҽڵ��޸���
        // left == 1 && right == 0 ��ڵ�������ͷ���ҽڵ��޸���
        // left == 0 && right == 1 ��ڵ����޸��ǣ��ҽڵ�����ͷ
        // left == 0 && right == 2 ��ڵ��޸��ǣ��ҽڵ㸲��
        // left == 2 && right == 0 ��ڵ㸲�ǣ��ҽڵ��޸���
        else if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        // ���3
        // left == 1 && right == 2 ��ڵ�������ͷ���ҽڵ��и���
        // left == 2 && right == 1 ��ڵ��и��ǣ��ҽڵ�������ͷ
        // left == 1 && right == 1 ���ҽڵ㶼������ͷ
        // �������ǰ�δ�����Ѹ���
        else if (left == 1 || right == 1)
            return 2;
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        res = 0;
        // ���4,root�޸���
        if (postorder(root) == 0)
            res++;
        return res;
    }
};
