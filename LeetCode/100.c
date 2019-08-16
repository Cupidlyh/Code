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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))//��һ��Ϊ��ʱ��˵������һ��
        return false;
    if(p!=NULL&&q!=NULL)
        if(p->val!=q->val)//����ֵ��ͬʱ��˵������һ��
            return false;
        else{//����ͬʱ�����������ж�
            if(isSameTree(p->left,q->left)==false)
                return false;
            if(isSameTree(p->right,q->right)==false)
                return false;
        }
    return true;
}
