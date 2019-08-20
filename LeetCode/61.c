#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *ans=head;//ans是返回的链表
    if(head==NULL){//当所传进来的链表无节点时
        ans=NULL;
        return ans;
    }
    struct ListNode *obj=ans;//用obj来进行操作
    int arr[5000]={0},n=0,arr1[1000]={0},m=0;
    while(head!=NULL){//用arr记录链表中的所有元素，
        arr[n++]=head->val;//n记录链表的节点数量
        head=head->next;
    }
    int k1=k%n,k2=k1;
    while(k1>0){//arr1记录有哪些在后面的元素需要移动到前面
        arr1[m++]=arr[--n];
        k1--;
    }
    if(k2==0)//k2为0说明原链表的结构不用改变
        return ans;
    else
        obj->val=arr1[--m];
    while(m>0){//移动后面的节点到前面
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=arr1[--m];
        obj->next=temp;
        obj=obj->next;
    }
    while(k1<n){//前面的节点往后移k个位置
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=arr[k1++];
        obj->next=temp;
        obj=obj->next;
    }
    obj->next=NULL;
    return ans;
}
