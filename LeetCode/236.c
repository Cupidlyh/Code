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
    //����������ĸ��ڵ���p,q,NULL�������е�һ��,�򷵻�root: 1.p����q��root,�����ߵ��������������root 2.root�ǿյ�,���������ǿ���,����NULL,Ҳ�Ƿ���root
    if(root == NULL || root == p || root == q)
        return root;
    struct TreeNode *left = lowestCommonAncestor(root -> left,p,q);//ȥ���������Ƿ���Է��ʵ�p��q,���ѽ�����ظ�left
    struct TreeNode *right = lowestCommonAncestor(root -> right,p,q);//ȥ���������Ƿ���Է��ʵ�p��q,���ѽ�����ظ�right
    if(left != NULL && right != NULL)//�� left != NULL �� right != NULL ʱ, ˵��p��q�ֱ����������������. ��ô, root���ǹ���������
        return root;
    else if(left == NULL && right != NULL)//�� left == NULL �� right != NULL ʱ, ˵��p��q�Ĺ������ȳ�������������. ����right.
        return right;
    else if(right == NULL && left != NULL)//�� left != NULL �� right == NULL ʱ, ˵��p��q�Ĺ������ȳ�������������. ����left.
        return left;
    return ;
}
