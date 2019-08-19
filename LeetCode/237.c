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
        node->val=node->next->val;//用下一节点的值覆盖掉当前节点的值
        if(node->next->next==NULL){//对链表结束的判断
            node->next=NULL;
            break;
        }
        else
            node=node->next;
    }
}
