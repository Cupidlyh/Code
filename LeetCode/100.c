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
    if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))//有一个为空时，说明树不一样
        return false;
    if(p!=NULL&&q!=NULL)
        if(p->val!=q->val)//结点的值不同时，说明树不一样
            return false;
        else{//当相同时，继续进行判断
            if(isSameTree(p->left,q->left)==false)
                return false;
            if(isSameTree(p->right,q->right)==false)
                return false;
        }
    return true;
}
