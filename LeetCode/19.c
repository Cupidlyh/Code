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
    struct ListNode *ans=head;//ans�Ƿ��ص�����
    struct ListNode *p=head;
    struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));//temp��ͷ�ڵ㣬����headǰ
    temp->next=head;
    int num=0,i;
    while(head!=NULL){
        head=head->next;
        num++;//��¼�ڵ�ĸ���
    }
    i=num-n+1;//�������������λ��
    if(i==1){//��ɾ���ڵ���������һ��ʱ
        ans=ans->next;
        return ans;
    }
    while(i>1){//�ҵ���Ҫɾ���ڵ��λ��
        p=p->next;
        temp=temp->next;
        i--;
    }
    temp->next=p->next;//ɾ���ڵ�
    return ans;
}
