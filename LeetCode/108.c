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

struct TreeNode* ToBST(int *nums,int left,int right) {
     if(left>right)//左大于右的话就没有中间值，所以返回NULL
        return NULL;
	 int mid=(left+right)/2;//二分中值
     struct TreeNode *root =(struct TreeNode *)malloc(sizeof(struct TreeNode));
     root->val=nums[mid];
	 root->left=ToBST(nums,left,mid-1);//mid-1是对左半部分进行递归
	 root->right=ToBST(nums,mid+1,right);//mid+1是对右半部分进行递归
	 return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return ToBST(nums,0,numsSize-1);
}
