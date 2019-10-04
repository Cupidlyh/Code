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

int sum,k;

void Pathsummation(struct TreeNode* root,int *temp) {
    temp[k] = root->val;//��ǰ�ڵ��ֵ������ʱ������
    k = k + 1;
    if(root->left == NULL && root->right == NULL) {//���ҵ��Ӹ���Ҷ�ӽڵ��·��
        int i=0,j;
        for(j = k-1;j >= 0;j--)
            sum = sum + temp[j]*pow(10,i++);//�������еĸ���Ҷ�ӽڵ������֮��
        k = k - 1;
        return ;
    }
    if(root->left != NULL)//��ǰ�ڵ�������ʱ
        Pathsummation(root->left,temp);
    if(root->right != NULL)//��ǰ�ڵ����Һ���ʱ
        Pathsummation(root->right,temp);
    k = k - 1;
    return ;
}

int sumNumbers(struct TreeNode* root){
    if(root == NULL)
        return 0;
    sum = 0;
    k = 0;
    int temp[1000] = {0};
    Pathsummation(root,temp);
    return sum;
}
