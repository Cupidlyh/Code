#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ans=(struct ListNode *)malloc(sizeof(struct ListNode));//返回去的链表的首个节点
    struct ListNode *obj=ans;//用obj来进行一系列操作
    if(l1==NULL||l2==NULL){//其中一个是空链表时
        if(l1==NULL&&l2==NULL){
            ans=NULL;
            return ans;
        }
        if(l1==NULL){
            ans=l2;
            return ans;
        }
        if(l2==NULL){
            ans=l1;
            return ans;
        }
    }
    if(l1->val>=l2->val){//比较两个链表的首元素
        obj->val=l2->val;
        l2=l2->next;
    }
    else{
        obj->val=l1->val;
        l1=l1->next;
    }
    while(l1!=NULL&&l2!=NULL){//循环比较，直到一个为空
        if(l1->val>=l2->val){
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=l2->val;
            obj->next=temp;
            obj=obj->next;
            l2=l2->next;
        }
        else{
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=l1->val;
            obj->next=temp;
            obj=obj->next;
            l1=l1->next;
        }
    }
    if(l1==NULL&&l2==NULL)
        obj->next=NULL;
    if(l1==NULL)//如果while循环结束只有一个链表为空
        obj->next=l2;//另一个链表剩余元素直接加到返回的链表里
    if(l2==NULL)
        obj->next=l1;
    return ans;
}
