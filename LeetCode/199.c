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

int* rightSideView(struct TreeNode* root, int* returnSize){
    int *res=(int *)malloc(1000*sizeof(int));//������ͼ������
    int num=0,i,depth=maxDepth(root);
    memset(res,0,sizeof(res));//�����ʼ��
    int *col=(int *)malloc((depth+1)*sizeof(int));//����һ����¼ÿ���м���Ԫ�ص�һά����
    int **arr =(int **)malloc(sizeof(int*)*(depth+1));//���ٶ�ά����
    for(i=0; i<(depth+1); i++)
        arr[i]=(int *)malloc(sizeof(int)*500);
    memset(col,0,(depth+1)*sizeof(int));//��col�����ʼ��
    levelorder(root,arr,col,0);//��α���
    for(i=0;i<depth;i++)//����α�����Ķ�ά�����ÿһ�е����һ��Ԫ�ش��res�����У���Ϊ����ͼ
        res[num++]=arr[i][col[i]-1];
    *returnSize=num;
    return res;
}
