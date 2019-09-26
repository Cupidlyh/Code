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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int maxDepth(struct TreeNode* root){//��������������
    if(root==NULL)
        return 0;
    int depth_left = maxDepth(root->left);
    int depth_right = maxDepth(root->right);
    return depth_left>depth_right?depth_left+1:depth_right+1;
}
//level���ǵ�ǰԪ�ش洢����
void levelorder(struct TreeNode *p,int **arr,int *col,int level){
    if(p==NULL)//���ڵ�Ϊ�վͷ���
        return ;
    arr[level][col[level]++]=p->val;//��Ԫ�طŽ���ά����
    levelorder(p->left,arr,col,level+1);//�������ӣ�������1
    levelorder(p->right,arr,col,level+1);//�����Һ��ӣ�������1
    return ;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize=maxDepth(root);//*returnSize��¼��������
    int i,temp,j;
    int *col=(int *)malloc(4000*sizeof(int));//����һ����¼ÿ�м���Ԫ�ص�һά����
    int **arr =(int **)malloc(sizeof(int*)*4000);//���ٶ�ά����
    for(i=0; i<4000; i++)
        arr[i]=(int *)malloc(sizeof(int)*500);
    memset(col,0,4000*sizeof(int));//��col�����ʼ��
    levelorder(root,arr,col,0);//��α���
    *returnColumnSizes=col;
    for(i=1;i<*returnSize;i=i+2) {//�������е�Ԫ�ؽ��з�ת
        for(j=0;j<col[i]/2;j++) {
            temp=arr[i][j];
            arr[i][j]=arr[i][col[i]-1-j];
            arr[i][col[i]-1-j]=temp;
        }
    }
    return arr;
}
