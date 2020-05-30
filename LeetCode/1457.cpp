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
    int arr[100009];//存储每次遍历根节点到叶子节点路径上的节点值
    int book[10];//记录路径上1到9出现次数
    int ans;//答案

    void dfs(TreeNode* p,int i) {
        arr[i] = p -> val;
        if(p -> left == NULL && p -> right == NULL) {//遍历到叶子节点（找到一条路径）
            memset(book,0,sizeof(book));
            int j;
            for(j = 0; j <= i; j++) {//统计路径中数字出现次数
                book[arr[j]]++;
            }
            int odd = 0;
            if(i % 2 != 0) {//路径节点数量为偶数（回文串中数字数量必须全为偶数）
                for(j = 1; j <= 9; j++) {
                    if(book[j] % 2 != 0)
                        return ;
                }
                ans++;
            }
            else {//路径节点数量为奇数（回文串中数字数量必须只有一个数字数量为奇数，其余数量全为偶数）
                for(j = 1; j <= 9; j++) {
                    if(book[j] % 2 != 0)
                        odd++;
                    if(odd >= 2)
                        return ;
                }
                ans++;
            }
            return ;
        }
        if(p -> left)
            dfs(p -> left,i + 1);
        if(p -> right)
            dfs(p -> right,i + 1);
        return ;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL)
            return 0;
        ans = 0;
        memset(arr,0,sizeof(0));
        dfs(root,0);
        return ans;
    }
};
