#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL){//����������Ϊ��ʱ
        struct ListNode *l1=NULL;
        return l1;
    }
    struct ListNode *l1=head;//l1��Ϊ���ص�����
    struct ListNode *l2=head->next;
    struct ListNode *l3=head;
    while(l3!=NULL&&l2!=NULL){//ѭ������
        if(l3->val==l2->val){//���ֵ���
            l3->next=l2->next;//ָ��Խ������ָ����һ��
            l2=l2->next;
        }
        else{
            l3=l3->next;
            l2=l2->next;
        }
    }
    return l1;
}

