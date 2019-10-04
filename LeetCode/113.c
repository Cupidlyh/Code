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

//sumpathΪ����·���ܺͣ�kΪ��ʱ����temp��Ԫ�ش洢��λ�ã�accΪ����
int sumpath,k,acc;

void Pathsummation(struct TreeNode* root, int sum,int **res,int *col,int *temp) {
    temp[k] = root->val;//��ǰ�ڵ��ֵ������ʱ������
    k=k+1;
    sumpath = sumpath + root->val;//��·���ĺͼ��ϵ�ǰ����Ľڵ�ֵ
    if(root->left == NULL && root->right == NULL && sumpath == sum) {//��������ʱ��˵���ҵ���һ��·����������
        for(int i=0;i<k;i++)//����ʱ�����е�Ԫ�ش�����������
            res[acc][i] = temp[i];
        col[acc++] = k;//��¼�´��е�Ԫ�ظ���
            k = k - 1;
        sumpath = sumpath - root->val;//��Ϊ���ص���һ������������У�����Ҫ��·���ĺͼ�ȥ��ǰ����Ľڵ�ֵ
        return ;
    }
    if(root->left == NULL && root->right == NULL && sumpath != sum){//����������ʱ
        k = k - 1;
        sumpath = sumpath - root->val;//��Ϊ���ص���һ������������У�����Ҫ��·���ĺͼ�ȥ��ǰ����Ľڵ�ֵ
        return ;
    }
    if(root->left != NULL)//��ǰ�ڵ�������ʱ
        Pathsummation(root->left,sum,res,col,temp);
    if(root->right != NULL)//��ǰ�ڵ����Һ���ʱ
        Pathsummation(root->right,sum,res,col,temp);
    k = k - 1;
    sumpath = sumpath - root->val;//������ֽڵ���Һ��ӱ����꣬��Ҫ�������˵���һ��
    return ;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    sumpath = 0;
    k = 0;
    acc = 0;
    *returnSize = 0;
    int *col = (int *)malloc(1000*sizeof(int));//����һ����¼ÿ��Ԫ�ظ���������
    int **res = (int **)malloc(sizeof(int*)*1000);//���ٶ�ά������������
    for(int i=0; i<1000; i++)
        res[i]=(int *)malloc(sizeof(int)*1000);
    int temp[1000] = {0};
    if(root == NULL)//�������������κνڵ�ʱ
        return res;
    Pathsummation(root,sum,res,col,temp);
    *returnSize = acc;
    *returnColumnSizes = col;
    return res;
}
