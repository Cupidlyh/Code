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
    unordered_map<int, int> index;

    TreeNode* Build(vector<int>& preorder, vector<int>& inorder,int prel,int prer,int inl,int inr) {
        if(prel > prer)
            return nullptr;
        //ǰ������еĵ�һ���ڵ���Ǹ��ڵ�
        int preroot = prel;
        //����������ж�λ���ڵ�
        int inroot = index[preorder[prel]];
        //�õ��������еĽڵ���Ŀ
        int value = inroot - inl;
        //�ȰѸ��ڵ㽨������
        TreeNode* root = new TreeNode(preorder[preroot]);
        //�ݹ�ع����������������ӵ����ڵ�
        //��������С��� ��߽�+1 ��ʼ�� value����Ԫ�ؾͶ�Ӧ����������С��� ��߽� ��ʼ�� ���ڵ㶨λ-1����Ԫ��
        root -> left = Build(preorder,inorder,prel + 1,prel + value,inl,inroot - 1);
        //�ݹ�ع����������������ӵ����ڵ�
        //��������С��� ��߽�+1+�������ڵ���Ŀ ��ʼ�� �ұ߽硹��Ԫ�ؾͶ�Ӧ����������С��� ���ڵ㶨λ+1 �� �ұ߽硹��Ԫ��
        root -> right = Build(preorder,inorder,prel + value + 1,prer,inroot + 1,inr);
        return root;
    }

    //ǰ�������˳���Ǹ����ң����������˳���������
    //ǰ����������Ǹ���㣬������ڵ���������������ð�����ֳ����������ֶ�Ӧ�������������ԾͿ��Եݹ����
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        //�����ϣӳ�䣬�������ǿ��ٶ�λ���ڵ�
        for(int i = 0; i < n; i++)
            index[inorder[i]] = i;
        return Build(preorder,inorder,0,n - 1,0,n - 1);
    }
};
