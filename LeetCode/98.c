#include <stdio.h>
#include <stdlib.h>

static int arr[10000],j;//全局变量

void inorder(struct TreeNode* t){//树的中序遍历
    if(t){
        inorder(t->left);
        arr[j++]=t->val;//将元素存进数组中
        inorder(t->right);
    }
}

bool isValidBST(struct TreeNode* root){
    int i;
    j=0;
    memset(arr,0,sizeof(arr));//数组初始化
    inorder(root);//中序遍历
    for(i=0;i<j-1;i++){
        if(arr[i]>=arr[i+1]){//满足此条件就说明不是二叉搜索树
            return false;
        }
    }
    return true;
}
