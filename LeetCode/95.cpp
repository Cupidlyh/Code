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
    vector<TreeNode*> createTrees(int start, int end) {
        if (start > end) {
            return { nullptr };
        }
        vector<TreeNode*> allTrees;
        // ö�ٿ��и��ڵ�
        for (int i = start; i <= end; i++) {
            // ������п��е�����������
            vector<TreeNode*> leftTrees = createTrees(start, i - 1);
            // ������п��е�����������
            vector<TreeNode*> rightTrees = createTrees(i + 1, end);
            // ��������������ѡ��һ������������������������ѡ��һ����������ƴ�ӵ����ڵ���
            for(int j = 0; j < leftTrees.size(); j++) {
                for(int k = 0; k < rightTrees.size(); k++) {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = leftTrees[j];
                    currTree->right = rightTrees[k];
                    allTrees.push_back(currTree);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return createTrees(1, n);
    }
};
