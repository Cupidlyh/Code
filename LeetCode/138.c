#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;

        //��һ��������ԭʼ�Ľڵ㣬�����������
        Node* p=head;
        while(p){
            Node *q=(Node *)malloc(sizeof(Node));
            q->val=p->val;//���½��Ľڵ㸳ֵ
            q->next=p->next;
            p->next=q;
            p=q->next;
        }

        //�ڶ���������ӵĽڵ�random ���ӵ�ԭʼ�ڵ�random����һ��λ��
        Node* p1=head;
        while(p1){
            Node* q=p1->next;
            if(p1->random==NULL)
                q->random=NULL;
            else
                q->random=p1->random->next;
            p1=q->next;//������һ���ڵ�
        }

        //���������ָ�ԭʼ�����õ�������
        Node* p2=head;
        Node* copy=head->next;
        Node* copy1=head->next;
        while(p2->next->next!=NULL){
            p2->next=copy->next;
            p2=copy->next;
            copy->next=p2->next;
            copy=p2->next;
        }
        p2->next=NULL;
        copy->next=NULL;
        return copy1;
    }
};
