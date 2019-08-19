#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *ans=(struct ListNode *)malloc(sizeof(struct ListNode));//ans作为返回链表的首个节点
    if(head==NULL){//当传进来的链表为空时
        ans=NULL;
        return ans;
    }
    struct ListNode *obj=ans;//真正的链表连接的操作用obj来操作
    int arr[5000]={0},n=0;
    while(head!=NULL){
        arr[n++]=head->val;//将链表元素存进数组中
        head=head->next;
    }
    n--;
    obj->val=arr[n--];
    while(n>=0){//构建新的链表
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=arr[n--];
        obj->next=temp;
        obj=obj->next;
    }
    obj->next=NULL;
    return ans;
}
