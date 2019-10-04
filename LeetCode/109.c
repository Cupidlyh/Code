#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int arr[100000];

struct TreeNode* ToBST(int left,int right) {
    if(left > right)
        return NULL;
    int mid = (left + right) / 2;//二分中值
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
	root->left = ToBST(left,mid-1);//注意mid-1 对左半部分进行递归
	root->right = ToBST(mid+1,right);//注意mid+1 对右半部分进行递归
	return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    int k = 0;
    while(head != NULL){//将链表的节点值存进一个一维数组中
        arr[k++] = head->val;
        head = head->next;
    }
    return ToBST(0,k-1);
}
