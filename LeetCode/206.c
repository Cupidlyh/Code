#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *ans=(struct ListNode *)malloc(sizeof(struct ListNode));//ans��Ϊ����������׸��ڵ�
    if(head==NULL){//��������������Ϊ��ʱ
        ans=NULL;
        return ans;
    }
    struct ListNode *obj=ans;//�������������ӵĲ�����obj������
    int arr[5000]={0},n=0;
    while(head!=NULL){
        arr[n++]=head->val;//������Ԫ�ش��������
        head=head->next;
    }
    n--;
    obj->val=arr[n--];
    while(n>=0){//�����µ�����
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=arr[n--];
        obj->next=temp;
        obj=obj->next;
    }
    obj->next=NULL;
    return ans;
}
