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

void postorder(struct TreeNode* t){//�������
    if(t){
        postorder(t->left);//�ݹ�
        postorder(t->right);
        arr[n++]=t->val;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    n=0;//n������¼������Ԫ�ص�����
    memset(arr,0,sizeof(arr));//�����ʼ��
    postorder(root);
    *returnSize=n;
    return arr;
}
