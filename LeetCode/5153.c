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

int maxDepth(struct TreeNode* root){//��������������
    if(root==NULL)
        return 0;
    int depth_left = maxDepth(root->left);
    int depth_right = maxDepth(root->right);
    return depth_left>depth_right?depth_left+1:depth_right+1;
}

//level���ǵ�ǰԪ�ش洢������
void levelorder(struct TreeNode *p,int **arr,int *col,int level){
    if(p==NULL)//���ڵ�Ϊ�վͷ���
        return ;
    arr[level][col[level]++]=p->val;//��Ԫ�طŽ���ά����
    levelorder(p->left,arr,col,level+1);//�������ӣ�������1
    levelorder(p->right,arr,col,level+1);//�����Һ��ӣ�������1
    return ;
}

int deepestLeavesSum(struct TreeNode* root){
    int deep=maxDepth(root);//deep��¼��������(Ҳ���Ƕ����������)
    int i,sum = 0;
    int *col=(int *)malloc((deep+1)*sizeof(int));//����һ����¼ÿ���м���Ԫ�ص�һά����
    int **arr =(int **)malloc(sizeof(int*)*(deep+1));//���ٶ�ά����(�洢��α����Ľ��)
    for(i=0; i<(deep+1); i++)
        arr[i]=(int *)malloc(sizeof(int)*5000);
    memset(col,0,(deep+1)*sizeof(int));//��col�����ʼ��
    levelorder(root,arr,col,0);//��α���
    for(i = 0; i < col[deep - 1]; i++)//��ά�������һ���д洢��Ԫ�ؾ��ǲ��������Ҷ�ӽڵ��ֵ
        sum = sum + arr[deep - 1][i];
    return sum;
}
