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

void inorder(struct TreeNode* t){//�ݹ��������
    if(t){
        inorder(t->left);
        arr[n++]=t->val;
        inorder(t->right);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    n=0;//n������¼������Ԫ�صĸ���
    memset(arr,0,sizeof(arr));//����ĳ�ʼ��
    inorder(root);
    *returnSize=n;
    return arr;
}
