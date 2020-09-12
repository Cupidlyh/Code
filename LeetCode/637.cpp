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
    //���������������
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int depth_left = maxDepth(root->left);
        int depth_right = maxDepth(root->right);
        return depth_left > depth_right ? depth_left + 1 : depth_right + 1;
    }

    //level���ǵ�ǰԪ�ش洢����
    void levelorder(TreeNode* root,vector<vector<double>>& arr,int level) {//��α���
        if (root == NULL) {
            return ;
        }
        arr[level][0] += root -> val;
        arr[level][1]++;
        levelorder(root -> left,arr,level + 1);
        levelorder(root -> right,arr,level + 1);
        return ;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        int dep = maxDepth(root);
        //arr[level][0]�洢����Ԫ�ص��ܺͣ�arr[level][1]�洢����Ԫ�صĸ���
        vector<vector<double>> arr(dep,vector<double>(2,0));
        vector<double> res;
        levelorder(root,arr,0);
        for (int i = 0; i < dep; i++) {
            res.push_back(arr[i][0] / arr[i][1]);
        }
        return res;
    }
};
