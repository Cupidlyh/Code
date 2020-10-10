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
    //计算树的最大深度
    int maxDepth(struct TreeNode* root){
        if(root == NULL)
            return 0;
        int depth_left = maxDepth(root -> left);
        int depth_right = maxDepth(root -> right);
        return depth_left > depth_right ? depth_left + 1 : depth_right + 1;
    }

    //level就是当前元素存储的行
    void levelorder(struct TreeNode *p,vector<vector<int>>& arr,int level){//层次遍历
        if(p == NULL)
            return ;
        arr[level].push_back(p -> val);
        levelorder(p -> left,arr,level + 1);
        levelorder(p -> right,arr,level + 1);
        return ;
    }

    bool isEvenOddTree(TreeNode* root) {
        //存放层次遍历后的结果
        vector<vector<int>> arr(100000);
        levelorder(root,arr,0);
        int dep = maxDepth(root);
        for (int j = 0; j < dep; j++) {
            for (int k = 0; k < arr[j].size(); k++) {
                if (j % 2 == 0) {
                    if (arr[j][k] % 2 == 0)
                        return false;
                    if (k != 0) {
                        if (arr[j][k] <= arr[j][k - 1])
                            return false;
                    }
                }
                else {
                    if (arr[j][k] % 2 != 0)
                        return false;
                    if (k != 0) {
                        if (arr[j][k] >= arr[j][k - 1])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
