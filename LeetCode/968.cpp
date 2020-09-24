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
        // 空节点，该节点有覆盖
        if (root == NULL)
            return 2;
        int left = postorder(root -> left);
        int right = postorder(root -> right);
        // 情况1
        // 左右节点都有覆盖
        if (left == 2 && right == 2)
            return 0;
         // 情况2
        // left == 0 && right == 0 左右节点无覆盖
        // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
        // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
        // left == 0 && right == 2 左节点无覆盖，右节点覆盖
        // left == 2 && right == 0 左节点覆盖，右节点无覆盖
        else if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        // 情况3
        // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
        // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
        // left == 1 && right == 1 左右节点都有摄像头
        // 其他情况前段代码均已覆盖
        else if (left == 1 || right == 1)
            return 2;
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        res = 0;
        // 情况4,root无覆盖
        if (postorder(root) == 0)
            res++;
        return res;
    }
};
