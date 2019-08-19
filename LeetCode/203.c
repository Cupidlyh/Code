#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *l1=head;//返回的链表的首个节点
    if(head==NULL)//当链表为空时
        return l1;
    if(head->next==NULL){//当链表只有一个节点时
        if(head->val==val){
            l1=NULL;
            return l1;
        }
        else
            return l1;
    }
    while(head!=NULL&&head->val==val){//从首节点开始的一段都等于所给值时
        l1=head->next;
        head=head->next;
        if(head==NULL){//链表所有的节点值都等于所给值
            l1=NULL;
            return l1;
        }
    }
    struct ListNode *l2=l1->next;
    struct ListNode *l3=l1;
    while(l2!=NULL&&l3!=NULL){//循环的条件
        if(l2->val==val){
            l3->next=l2->next;
            l2=l3->next;
        }
        else{
            l2=l2->next;
            l3=l3->next;
        }
    }
    return l1;
}
