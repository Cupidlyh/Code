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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static n,arr[5000];//ȫ�ֱ���

void preorder(struct TreeNode* t){//�������
    if(t){
        arr[n++]=t->val;
        preorder(t->left);//�ݹ�
        preorder(t->right);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    n=0;//n������¼������Ԫ�ص�����
    memset(arr,0,sizeof(arr));//�����ʼ��
    preorder(root);
    *returnSize=n;
    return arr;
}
