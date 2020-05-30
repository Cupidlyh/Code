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
    int arr[100009];//�洢ÿ�α������ڵ㵽Ҷ�ӽڵ�·���ϵĽڵ�ֵ
    int book[10];//��¼·����1��9���ִ���
    int ans;//��

    void dfs(TreeNode* p,int i) {
        arr[i] = p -> val;
        if(p -> left == NULL && p -> right == NULL) {//������Ҷ�ӽڵ㣨�ҵ�һ��·����
            memset(book,0,sizeof(book));
            int j;
            for(j = 0; j <= i; j++) {//ͳ��·�������ֳ��ִ���
                book[arr[j]]++;
            }
            int odd = 0;
            if(i % 2 != 0) {//·���ڵ�����Ϊż�������Ĵ���������������ȫΪż����
                for(j = 1; j <= 9; j++) {
                    if(book[j] % 2 != 0)
                        return ;
                }
                ans++;
            }
            else {//·���ڵ�����Ϊ���������Ĵ���������������ֻ��һ����������Ϊ��������������ȫΪż����
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
