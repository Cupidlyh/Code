#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *ans=head;//ans�Ƿ��ص�����
    if(head==NULL){//�����������������޽ڵ�ʱ
        ans=NULL;
        return ans;
    }
    struct ListNode *obj=ans;//��obj�����в���
    int arr[5000]={0},n=0,arr1[1000]={0},m=0;
    while(head!=NULL){//��arr��¼�����е�����Ԫ�أ�
        arr[n++]=head->val;//n��¼����Ľڵ�����
        head=head->next;
    }
    int k1=k%n,k2=k1;
    while(k1>0){//arr1��¼����Щ�ں����Ԫ����Ҫ�ƶ���ǰ��
        arr1[m++]=arr[--n];
        k1--;
    }
    if(k2==0)//k2Ϊ0˵��ԭ����Ľṹ���øı�
        return ans;
    else
        obj->val=arr1[--m];
    while(m>0){//�ƶ�����Ľڵ㵽ǰ��
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=arr1[--m];
        obj->next=temp;
        obj=obj->next;
    }
    while(k1<n){//ǰ��Ľڵ�������k��λ��
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=arr[k1++];
        obj->next=temp;
        obj=obj->next;
    }
    obj->next=NULL;
    return ans;
}
