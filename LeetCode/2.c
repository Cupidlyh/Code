#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int arr1[10000]={0},arr2[10000]={0},res[10000]={0},a1=0,a2=0;//res数组是记录相加的结果
    while(l1!=NULL){//arr1数组存储l1链表的节点值
        arr1[a1++]=l1->val;
        l1=l1->next;
    }
    while(l2!=NULL){//arr2数组存储l2链表的节点值
        arr2[a2++]=l2->val;
        l2=l2->next;
    }
    int carry=0,i,len;//carry记录进位的数
    len=a1>a2?a1:a2;//len记录长的数字的位数
    for(i=0;i<len+1;i++){//小于len+1是为了防止两个数相加后总的整个长度比长的数字的位数加1位
        if(arr1[i]+arr2[i]+carry>=10){//判断是否有进位
            res[i]=(arr1[i]+arr2[i]+carry)%10;//记录当前位的数字
            carry=(arr1[i]+arr2[i]+carry)/10;//记录进位数
        }
        else{
            res[i]=arr1[i]+arr2[i]+carry;
            carry=0;//无进位数时，carry要变为0，等待重新记录下次进位值
        }
    }
    if(res[len]!=0)//判断是否总长度加1
        len=len+1;
    struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p=head;
    head->val=res[0];
    for(i=1;i<len;i++){//构建新的返回链表
        struct ListNode *q=(struct ListNode *)malloc(sizeof(struct ListNode));
        q->val=res[i];
        p->next=q;
        p=p->next;
    }
    p->next=NULL;
    return head;
}
