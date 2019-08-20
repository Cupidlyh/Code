#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* ans;//ans�Ƿ��ص�����
    if(head==NULL||head->next==NULL){//����������ֻ��һ���ڵ���޽ڵ�ʱ
        ans=head;
        return ans;
    }
    struct ListNode* min=(struct ListNode* )malloc(sizeof(struct ListNode));//��С������ֵ�Ľڵ�
    struct ListNode* max=(struct ListNode* )malloc(sizeof(struct ListNode));//����ڵ�������ֵ�Ľڵ�
    struct ListNode* max1=max;
    struct ListNode* min1=min;
    int num_min=0,num_max=0;//��¼���������нڵ������
    while(head!=NULL){//����һ������
        struct ListNode* temp=(struct ListNode* )malloc(sizeof(struct ListNode));
        if(head->val>=x){//����ڵ�������ֵ�Ľڵ�
            if(num_max==0)
                max->val=head->val;
            else{
                temp->val=head->val;
                max->next=temp;
                max=max->next;
            }
            num_max++;
        }
        else{//��С������ֵ�Ľڵ�ֵ
            if(num_min==0)
                min->val=head->val;
            else{
                temp->val=head->val;
                min->next=temp;
                min=min->next;
            }
            num_min++;
        }
        head=head->next;
    }
    if(num_min==0){//��û��С������ֵ�Ľڵ�ʱ
        ans=max1;
        max->next=NULL;
    }
    if(num_max==0){//��û�д��ڵ�������ֵ�Ľڵ�ʱ
        ans=min1;
        min->next=NULL;
    }
    if(num_max!=0&&num_min!=0){
        ans=min1;
        min->next=max1;
        max->next=NULL;
    }
    return ans;
}
