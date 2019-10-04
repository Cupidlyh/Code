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

 int k,row;//k是临时数组temp的下标，row记录存放结果的二维数组的行数

void path(struct TreeNode* root,char** res,int* temp) {
    temp[k] = root->val;//当前节点的值存入临时数组中
    k=k+1;
    if(root->left == NULL && root->right == NULL) {//当找到从根到叶子节点的路径
        int i=0;
        for(int j=0; j<k-1; j++)//按题意的形式存进结果数组中
            sprintf(res[row], "%s%d->", res[row], temp[j]);
        sprintf(res[row], "%s%d", res[row], temp[k-1]);
        row++;//行数加1
        k = k - 1;
        return ;
    }
    if(root->left != NULL)//当前节点有左孩子时
        path(root->left,res,temp);
    if(root->right != NULL)//当前节点有右孩子时
        path(root->right,res,temp);
    k = k - 1;
    return ;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    k = 0;
    row = 0;
    char **res = (char **)malloc(sizeof(char*)*1000);//开辟二维数组
    for(int i=0; i<1000; i++){
        res[i]=(char *)malloc(sizeof(char)*1000);
        memset(res[i],0,1000*sizeof(char));//对数组进行初始化
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

