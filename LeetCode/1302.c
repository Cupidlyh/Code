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

int maxDepth(struct TreeNode* root){//计算树的最大深度
    if(root==NULL)
        return 0;
    int depth_left = maxDepth(root->left);
    int depth_right = maxDepth(root->right);
    return depth_left>depth_right?depth_left+1:depth_right+1;
}

//level就是当前元素存储的行数
void levelorder(struct TreeNode *p,int **arr,int *col,int level){
    if(p==NULL)//当节点为空就返回
        return ;
    arr[level][col[level]++]=p->val;//将元素放进二维数组
    levelorder(p->left,arr,col,level+1);//遍历左孩子，行数加1
    levelorder(p->right,arr,col,level+1);//遍历右孩子，行数加1
    return ;
}

int deepestLeavesSum(struct TreeNode* root){
    int deep=maxDepth(root);//deep记录的是行数(也就是二叉树的深度)
    int i,sum = 0;
    int *col=(int *)malloc((deep+1)*sizeof(int));//开辟一个记录每行有几个元素的一维数组
    int **arr =(int **)malloc(sizeof(int*)*(deep+1));//开辟二维数组(存储层次遍历的结果)
    for(i=0; i<(deep+1); i++)
        arr[i]=(int *)malloc(sizeof(int)*5000);
    memset(col,0,(deep+1)*sizeof(int));//将col数组初始化
    levelorder(root,arr,col,0);//层次遍历
    for(i = 0; i < col[deep - 1]; i++)//二维数组最后一行中存储的元素就是层数最深的叶子节点的值
        sum = sum + arr[deep - 1][i];
    return sum;
}
