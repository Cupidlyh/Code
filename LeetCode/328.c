#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode* ans;//ans是返回的链表
    if(head==NULL||head->next==NULL){//当传进来的链表只有一个节点或者无节点时
        ans=head;
        return ans;
    }
    struct ListNode* odd=(struct ListNode* )malloc(sizeof(struct ListNode));//用来构建奇数位的链表
    struct ListNode* even=(struct ListNode* )malloc(sizeof(struct ListNode));//用来构建偶数位的链表
    struct ListNode* even1;
    odd->val=head->val;//链表的第一位先放进odd来
    head=head->next;
    ans=odd;//将ans连接到奇数链表的头部
    even->val=head->val;//链表的第二位先放进even来
    even1=even;
    head=head->next;
    int num=3;//num记录当前进行操作的节点的位置
    while(head!=NULL){//遍历链表
        struct ListNode* temp=(struct ListNode* )malloc(sizeof(struct ListNode));
        if(num%2!=0){//将所传链表的奇数位节点放进odd链表中
            temp->val=head->val;
            odd->next=temp;
            odd=odd->next;
        }
        else{//将所传链表的偶数位节点放进even链表中
            temp->val=head->val;
            even->next=temp;
            even=even->next;
        }
        head=head->next;
        num++;
    }
    even->next=NULL;
    odd->next=even1;//奇数链表的尾部连接到偶数链表的头部
    return ans;
}
