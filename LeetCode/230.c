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

static int arr[100000],j;//ȫ�ֱ���

void inorder(struct TreeNode* t){//�����������
    if(t){
        inorder(t->left);
        arr[j++]=t->val;//��Ԫ�ش��������
        inorder(t->right);
    }
}

int kthSmallest(struct TreeNode* root, int k){
    j=1;
    memset(arr,0,sizeof(arr));//�����ʼ��
    inorder(root);//�������
    return arr[k];//���ص�kС��Ԫ��
}
