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
    if(head==NULL||head->next==NULL)//����ֻ��һ���ڵ���޽ڵ�ʱ
        return true;
    if(head->next->next==NULL){//�����������ڵ�ʱ
        if(head->val==head->next->val)
            return true;
        else
            return false;
    }
    struct ListNode* l1=head;
    struct ListNode* l2=head->next;
    struct ListNode* l3=head->next->next;
    struct ListNode* p1=(struct ListNode*)malloc(sizeof(struct ListNode));//p1�����������˳��
    struct ListNode* p2=p1;
    p1->val=head->val;
    head=head->next;
    while(head!=NULL){//��������˳����p1
        struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=head->val;
        p1->next=temp;
        p1=p1->next;
        head=head->next;
    }
    p1->next=NULL;
    l1->next=NULL;
    while(l3!=NULL){//����ת
        l2->next=l1;
        l1=l2;
        l2=l3;
        l3=l3->next;
    }
    l2->next=l1;//����ת����׸��ڵ���l2
    while(p2!=NULL){//����������бȽ�
        if(p2->val!=l2->val)
            return false;
        p2=p2->next;
        l2=l2->next;
    }
    return true;
}
