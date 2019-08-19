#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ans=(struct ListNode *)malloc(sizeof(struct ListNode));//����ȥ��������׸��ڵ�
    struct ListNode *obj=ans;//��obj������һϵ�в���
    if(l1==NULL||l2==NULL){//����һ���ǿ�����ʱ
        if(l1==NULL&&l2==NULL){
            ans=NULL;
            return ans;
        }
        if(l1==NULL){
            ans=l2;
            return ans;
        }
        if(l2==NULL){
            ans=l1;
            return ans;
        }
    }
    if(l1->val>=l2->val){//�Ƚ������������Ԫ��
        obj->val=l2->val;
        l2=l2->next;
    }
    else{
        obj->val=l1->val;
        l1=l1->next;
    }
    while(l1!=NULL&&l2!=NULL){//ѭ���Ƚϣ�ֱ��һ��Ϊ��
        if(l1->val>=l2->val){
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=l2->val;
            obj->next=temp;
            obj=obj->next;
            l2=l2->next;
        }
        else{
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=l1->val;
            obj->next=temp;
            obj=obj->next;
            l1=l1->next;
        }
    }
    if(l1==NULL&&l2==NULL)
        obj->next=NULL;
    if(l1==NULL)//���whileѭ������ֻ��һ������Ϊ��
        obj->next=l2;//��һ������ʣ��Ԫ��ֱ�Ӽӵ����ص�������
    if(l2==NULL)
        obj->next=l1;
    return ans;
}
