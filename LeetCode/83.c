#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL){//当所传链表为空时
        struct ListNode *l1=NULL;
        return l1;
    }
    struct ListNode *l1=head;//l1作为返回的链表
    struct ListNode *l2=head->next;
    struct ListNode *l3=head;
    while(l3!=NULL&&l2!=NULL){//循环条件
        if(l3->val==l2->val){//如果值相等
            l3->next=l2->next;//指针越过此项指向下一项
            l2=l2->next;
        }
        else{
            l3=l3->next;
            l2=l2->next;
        }
    }
    return l1;
}

