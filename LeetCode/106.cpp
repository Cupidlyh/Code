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
    //��¼�������Ԫ�ض�Ӧ���±�
    unordered_map<int,int> mp;

    //inl,inr�����������������ұ߽磬pol,por�Ǻ��������������ұ߽�
    TreeNode* build_Tree(vector<int>& postorder,int inl,int inr,int pol,int por) {
        if (inl > inr || pol > por)
            return NULL;
        //���������������һ��Ԫ�ؾ��ǵ�ǰ���ڵ�
        int rootval = postorder[por];
        //inbit����������ֳ����������ִ���������������
        int inbit = mp[postorder[por]];
        TreeNode* node = new TreeNode(rootval);
        node -> left = build_Tree(postorder,inl,inbit - 1,pol,pol + (inbit - inl) - 1);
        node -> right = build_Tree(postorder,inbit + 1,inr,pol + (inbit - inl),por - 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return build_Tree(postorder,0,inorder.size() - 1,0,postorder.size() - 1);
    }
};
