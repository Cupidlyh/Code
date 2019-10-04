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
    int mid = (left + right) / 2;//������ֵ
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];
	root->left = ToBST(left,mid-1);//ע��mid-1 ����벿�ֽ��еݹ�
	root->right = ToBST(mid+1,right);//ע��mid+1 ���Ұ벿�ֽ��еݹ�
	return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    int k = 0;
    while(head != NULL){//������Ľڵ�ֵ���һ��һά������
        arr[k++] = head->val;
        head = head->next;
    }
    return ToBST(0,k-1);
}
