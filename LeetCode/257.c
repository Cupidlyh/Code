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

 int k,row;//k����ʱ����temp���±꣬row��¼��Ž���Ķ�ά���������

void path(struct TreeNode* root,char** res,int* temp) {
    temp[k] = root->val;//��ǰ�ڵ��ֵ������ʱ������
    k=k+1;
    if(root->left == NULL && root->right == NULL) {//���ҵ��Ӹ���Ҷ�ӽڵ��·��
        int i=0;
        for(int j=0; j<k-1; j++)//���������ʽ������������
            sprintf(res[row], "%s%d->", res[row], temp[j]);
        sprintf(res[row], "%s%d", res[row], temp[k-1]);
        row++;//������1
        k = k - 1;
        return ;
    }
    if(root->left != NULL)//��ǰ�ڵ�������ʱ
        path(root->left,res,temp);
    if(root->right != NULL)//��ǰ�ڵ����Һ���ʱ
        path(root->right,res,temp);
    k = k - 1;
    return ;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    k = 0;
    row = 0;
    char **res = (char **)malloc(sizeof(char*)*1000);//���ٶ�ά����
    for(int i=0; i<1000; i++){
        res[i]=(char *)malloc(sizeof(char)*1000);
        memset(res[i],0,1000*sizeof(char));//��������г�ʼ��
    }
    if(root == NULL) {
        *returnSize = 0;
        return res;
    }
    int temp[1000] = {0};
    path(root,res,temp);
    *returnSize = row;
    return res;
}

