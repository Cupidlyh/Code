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

struct TreeNode *base[1000];
int n;
long long int arr[1000];

int cmp(const void *a,const void *b) {//从小到大排序
    const long long int p1 = *(const long long int*)a;
    const long long int p2 = *(const long long int*)b;
    if (p1 < p2)
        return -1;
    else if (p1 > p2)
        return 1;
    return 0;
}

void inorder(struct TreeNode* t){//递归中序遍历
    if(t){
        inorder(t->left);
        base[n] = t;//存当前节点
        arr[n++] = t -> val;//存当前节点的值
        inorder(t->right);
    }
}

void recoverTree(struct TreeNode* root){
    n = 0;
    inorder(root);//中序遍历
    qsort(arr,n,sizeof(arr[0]),cmp);//排序
    int i,temp,num = 0;//num是为了记录找到第几个不同的元素
    for(i = 0; i < n; i++) {
        if(arr[i] != base[i] -> val) {//寻找不同的元素
            if(num == 0) {//当找到第一个不同的元素时
                temp = i;//记录下来这个下标
            }
            num++;
            if(num == 2)//当找到第二个不同的元素时
                break;
        }
    }
    num = base[temp] -> val;//交换两个节点的值
    base[temp] -> val = base[i] -> val;
    base[i] -> val = num;
}
