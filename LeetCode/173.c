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



typedef struct {
    int top;//数组的头指针
    int base;//数组的尾指针
    int arr[10000];
} BSTIterator;

void inorder(struct TreeNode* t,BSTIterator *p){//对二叉搜索树进行中序遍历
    if(t){
        inorder(t->left,p);
        p->arr[p->top++]=t->val;
        inorder(t->right,p);
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *obj=(BSTIterator *)malloc(sizeof(BSTIterator));
    obj->top=0;
    obj->base=0;
    memset(obj->arr,0,sizeof(obj->arr));//数组初始化
    inorder(root,obj);//中序遍历
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    int res=obj->arr[obj->base];
    obj->base++;
    return res;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    if(obj->top==obj->base)
        return false;
    return true;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/
