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
    if(head == NULL)//�б�Ϊ��ʱ������
        return true;
    if(root == NULL || head -> val != root -> val)//��Ϊ��ʱ����ֵ����ʱ���ؼ�
        return false;
    return judge(head -> next,root -> left) || judge(head -> next,root -> right);//�ݹ��ж����������е�ֵ���б��е�ֵ�Ƿ����
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if(head == NULL)//�б�Ϊ��ʱ������
        return true;
    if(root == NULL)//��Ϊ��ʱ���ؼ�
        return false;
    if(isSubPath(head,root -> left) == true)//�������ݹ�
        return true;
    if(isSubPath(head,root -> right) == true)//�������ݹ�
        return true;
    if(head -> val == root -> val) {//���ҵ����б��׸�ֵ������ĳ���ڵ�ֵ���
        if(judge(head -> next,root -> left) == true)//�ж��������е�ֵ�Ƿ���б���һ��ֵ���
            return true;
        if(judge(head -> next,root -> right) == true)//�ж��������е�ֵ�Ƿ���б���һ��ֵ���
            return true;
    }
    return false;
}
