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

bool judge(struct ListNode* head, struct TreeNode* root) {
    if(head == NULL)//列表为空时返回真
        return true;
    if(root == NULL || head -> val != root -> val)//根为空时或者值不等时返回假
        return false;
    return judge(head -> next,root -> left) || judge(head -> next,root -> right);//递归判断左右子树中的值和列表中的值是否相等
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if(head == NULL)//列表为空时返回真
        return true;
    if(root == NULL)//根为空时返回假
        return false;
    if(isSubPath(head,root -> left) == true)//左子树递归
        return true;
    if(isSubPath(head,root -> right) == true)//右子树递归
        return true;
    if(head -> val == root -> val) {//当找到了列表首个值和树中某个节点值相等
        if(judge(head -> next,root -> left) == true)//判断左子树中的值是否和列表下一个值相等
            return true;
        if(judge(head -> next,root -> right) == true)//判断右子树中的值是否和列表下一个值相等
            return true;
    }
    return false;
}
