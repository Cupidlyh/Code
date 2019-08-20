#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* ans;//ans是返回的链表
    if(head==NULL||head->next==NULL){//当所传链表只有一个节点或无节点时
        ans=head;
        return ans;
    }
    struct ListNode* min=(struct ListNode* )malloc(sizeof(struct ListNode));//存小于所给值的节点
    struct ListNode* max=(struct ListNode* )malloc(sizeof(struct ListNode));//存大于等于所给值的节点
    struct ListNode* max1=max;
    struct ListNode* min1=min;
    int num_min=0,num_max=0;//记录两个链表中节点的数量
    while(head!=NULL){//遍历一遍链表
        struct ListNode* temp=(struct ListNode* )malloc(sizeof(struct ListNode));
        if(head->val>=x){//存大于等于所给值的节点
            if(num_max==0)
                max->val=head->val;
            else{
                temp->val=head->val;
                max->next=temp;
                max=max->next;
            }
            num_max++;
        }
        else{//存小于所给值的节点值
            if(num_min==0)
                min->val=head->val;
            else{
                temp->val=head->val;
                min->next=temp;
                min=min->next;
            }
            num_min++;
        }
        head=head->next;
    }
    if(num_min==0){//当没有小于所给值的节点时
        ans=max1;
        max->next=NULL;
    }
    if(num_max==0){//当没有大于等于所给值的节点时
        ans=min1;
        min->next=NULL;
    }
    if(num_max!=0&&num_min!=0){
        ans=min1;
        min->next=max1;
        max->next=NULL;
    }
    return ans;
}
