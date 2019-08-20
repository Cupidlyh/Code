#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *ans=head;//ans是返回的链表
    struct ListNode *p=head;
    struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));//temp是头节点，加在head前
    temp->next=head;
    int num=0,i;
    while(head!=NULL){
        head=head->next;
        num++;//记录节点的个数
    }
    i=num-n+1;//计算出从正数的位置
    if(i==1){//当删除节点是正数第一个时
        ans=ans->next;
        return ans;
    }
    while(i>1){//找到所要删除节点的位置
        p=p->next;
        temp=temp->next;
        i--;
    }
    temp->next=p->next;//删除节点
    return ans;
}
