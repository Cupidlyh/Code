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
        //前序遍历中的第一个节点就是根节点
        int preroot = prel;
        //在中序遍历中定位根节点
        int inroot = index[preorder[prel]];
        //得到左子树中的节点数目
        int value = inroot - inl;
        //先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preroot]);
        //递归地构造左子树，并连接到根节点
        //先序遍历中「从 左边界+1 开始的 value」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root -> left = Build(preorder,inorder,prel + 1,prel + value,inl,inroot - 1);
        //递归地构造右子树，并连接到根节点
        //先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root -> right = Build(preorder,inorder,prel + value + 1,prer,inroot + 1,inr);
        return root;
    }

    //前序遍历的顺序是根左右，中序遍历的顺序是左根右
    //前序遍历的首是根结点，这个根节点在中序遍历中正好把数组分成左右两部分对应左右子树，所以就可以递归解题
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        //构造哈希映射，帮助我们快速定位根节点
        for(int i = 0; i < n; i++)
            index[inorder[i]] = i;
        return Build(preorder,inorder,0,n - 1,0,n - 1);
    }
};
