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
    struct ListNode *l1=head;//���ص�������׸��ڵ�
    if(head==NULL)//������Ϊ��ʱ
        return l1;
    if(head->next==NULL){//������ֻ��һ���ڵ�ʱ
        if(head->val==val){
            l1=NULL;
            return l1;
        }
        else
            return l1;
    }
    while(head!=NULL&&head->val==val){//���׽ڵ㿪ʼ��һ�ζ���������ֵʱ
        l1=head->next;
        head=head->next;
        if(head==NULL){//�������еĽڵ�ֵ����������ֵ
            l1=NULL;
            return l1;
        }
    }
    struct ListNode *l2=l1->next;
    struct ListNode *l3=l1;
    while(l2!=NULL&&l3!=NULL){//ѭ��������
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
