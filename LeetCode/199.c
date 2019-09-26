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

int* rightSideView(struct TreeNode* root, int* returnSize){
    int *res=(int *)malloc(1000*sizeof(int));//存右视图的数组
    int num=0,i,depth=maxDepth(root);
    memset(res,0,sizeof(res));//数组初始化
    int *col=(int *)malloc((depth+1)*sizeof(int));//开辟一个记录每行有几个元素的一维数组
    int **arr =(int **)malloc(sizeof(int*)*(depth+1));//开辟二维数组
    for(i=0; i<(depth+1); i++)
        arr[i]=(int *)malloc(sizeof(int)*500);
    memset(col,0,(depth+1)*sizeof(int));//将col数组初始化
    levelorder(root,arr,col,0);//层次遍历
    for(i=0;i<depth;i++)//将层次遍历后的二维数组的每一行的最后一个元素存进res数组中，即为右视图
        res[num++]=arr[i][col[i]-1];
    *returnSize=num;
    return res;
}
