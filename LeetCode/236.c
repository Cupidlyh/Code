#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    //如果二叉树的根节点是p,q,NULL三者其中的一种,则返回root: 1.p或者q是root,则两者的最近公共祖先是root 2.root是空的,即二叉树是空树,返回NULL,也是返回root
    if(root == NULL || root == p || root == q)
        return root;
    struct TreeNode *left = lowestCommonAncestor(root -> left,p,q);//去左子树看是否可以访问到p或q,并把结果返回给left
    struct TreeNode *right = lowestCommonAncestor(root -> right,p,q);//去右子树看是否可以访问到p或q,并把结果返回给right
    if(left != NULL && right != NULL)//当 left != NULL 且 right != NULL 时, 说明p和q分别出现在左右子树上. 那么, root就是公共祖先了
        return root;
    else if(left == NULL && right != NULL)//当 left == NULL 且 right != NULL 时, 说明p和q的公共祖先出现在右子树上. 返回right.
        return right;
    else if(right == NULL && left != NULL)//当 left != NULL 且 right == NULL 时, 说明p和q的公共祖先出现在左子树上. 返回left.
        return left;
    return ;
}
