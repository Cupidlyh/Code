#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if(head==NULL||head->next==NULL)//链表只有一个节点和无节点时
        return true;
    if(head->next->next==NULL){//链表有两个节点时
        if(head->val==head->next->val)
            return true;
        else
            return false;
    }
    struct ListNode* l1=head;
    struct ListNode* l2=head->next;
    struct ListNode* l3=head->next->next;
    struct ListNode* p1=(struct ListNode*)malloc(sizeof(struct ListNode));//p1存链表的正常顺序
    struct ListNode* p2=p1;
    p1->val=head->val;
    head=head->next;
    while(head!=NULL){//链表正常顺序存进p1
        struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=head->val;
        p1->next=temp;
        p1=p1->next;
        head=head->next;
    }
    p1->next=NULL;
    l1->next=NULL;
    while(l3!=NULL){//链表翻转
        l2->next=l1;
        l1=l2;
        l2=l3;
        l3=l3->next;
    }
    l2->next=l1;//链表翻转后的首个节点是l2
    while(p2!=NULL){//两个链表进行比较
        if(p2->val!=l2->val)
            return false;
        p2=p2->next;
        l2=l2->next;
    }
    return true;
}
