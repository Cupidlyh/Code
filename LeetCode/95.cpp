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
        // 枚举可行根节点
        for (int i = start; i <= end; i++) {
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTrees = createTrees(start, i - 1);
            // 获得所有可行的右子树集合
            vector<TreeNode*> rightTrees = createTrees(i + 1, end);
            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
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
