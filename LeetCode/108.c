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
     if(left>right)//������ҵĻ���û���м�ֵ�����Է���NULL
        return NULL;
	 int mid=(left+right)/2;//������ֵ
     struct TreeNode *root =(struct TreeNode *)malloc(sizeof(struct TreeNode));
     root->val=nums[mid];
	 root->left=ToBST(nums,left,mid-1);//mid-1�Ƕ���벿�ֽ��еݹ�
	 root->right=ToBST(nums,mid+1,right);//mid+1�Ƕ��Ұ벿�ֽ��еݹ�
	 return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return ToBST(nums,0,numsSize-1);
}
