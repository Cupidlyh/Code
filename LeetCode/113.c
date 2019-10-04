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

//sumpath为计算路径总和，k为临时数组temp的元素存储的位置，acc为行数
int sumpath,k,acc;

void Pathsummation(struct TreeNode* root, int sum,int **res,int *col,int *temp) {
    temp[k] = root->val;//当前节点的值存入临时数组中
    k=k+1;
    sumpath = sumpath + root->val;//总路径的和加上当前传入的节点值
    if(root->left == NULL && root->right == NULL && sumpath == sum) {//满足条件时，说明找到了一个路径满足题意
        for(int i=0;i<k;i++)//将临时数组中的元素存进结果数组中
            res[acc][i] = temp[i];
        col[acc++] = k;//记录下此行的元素个数
            k = k - 1;
        sumpath = sumpath - root->val;//因为返回到上一级程序接着运行，所以要总路径的和减去当前传入的节点值
        return ;
    }
    if(root->left == NULL && root->right == NULL && sumpath != sum){//不满足条件时
        k = k - 1;
        sumpath = sumpath - root->val;//因为返回到上一级程序接着运行，所以要总路径的和减去当前传入的节点值
        return ;
    }
    if(root->left != NULL)//当前节点有左孩子时
        Pathsummation(root->left,sum,res,col,temp);
    if(root->right != NULL)//当前节点有右孩子时
        Pathsummation(root->right,sum,res,col,temp);
    k = k - 1;
    sumpath = sumpath - root->val;//如果发现节点的右孩子遍历完，需要继续回退到上一级
    return ;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    sumpath = 0;
    k = 0;
    acc = 0;
    *returnSize = 0;
    int *col = (int *)malloc(1000*sizeof(int));//开辟一个记录每行元素个数的数组
    int **res = (int **)malloc(sizeof(int*)*1000);//开辟二维数组用来存结果
    for(int i=0; i<1000; i++)
        res[i]=(int *)malloc(sizeof(int)*1000);
    int temp[1000] = {0};
    if(root == NULL)//当给定的树无任何节点时
        return res;
    Pathsummation(root,sum,res,col,temp);
    *returnSize = acc;
    *returnColumnSizes = col;
    return res;
}
