#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    while(node->next){
        node->val=node->next->val;//����һ�ڵ��ֵ���ǵ���ǰ�ڵ��ֵ
        if(node->next->next==NULL){//������������ж�
            node->next=NULL;
            break;
        }
        else
            node=node->next;
    }
}
