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
    struct ListNode* ans;//ans�Ƿ��ص�����
    if(head==NULL||head->next==NULL){//��������������ֻ��һ���ڵ�����޽ڵ�ʱ
        ans=head;
        return ans;
    }
    struct ListNode* odd=(struct ListNode* )malloc(sizeof(struct ListNode));//������������λ������
    struct ListNode* even=(struct ListNode* )malloc(sizeof(struct ListNode));//��������ż��λ������
    struct ListNode* even1;
    odd->val=head->val;//����ĵ�һλ�ȷŽ�odd��
    head=head->next;
    ans=odd;//��ans���ӵ����������ͷ��
    even->val=head->val;//����ĵڶ�λ�ȷŽ�even��
    even1=even;
    head=head->next;
    int num=3;//num��¼��ǰ���в����Ľڵ��λ��
    while(head!=NULL){//��������
        struct ListNode* temp=(struct ListNode* )malloc(sizeof(struct ListNode));
        if(num%2!=0){//���������������λ�ڵ�Ž�odd������
            temp->val=head->val;
            odd->next=temp;
            odd=odd->next;
        }
        else{//�����������ż��λ�ڵ�Ž�even������
            temp->val=head->val;
            even->next=temp;
            even=even->next;
        }
        head=head->next;
        num++;
    }
    even->next=NULL;
    odd->next=even1;//���������β�����ӵ�ż�������ͷ��
    return ans;
}
