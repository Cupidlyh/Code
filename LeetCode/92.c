#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode *ans=(struct ListNode *)malloc(sizeof(struct ListNode));//ans�Ƿ���������׸��ڵ�
    struct ListNode *obj=ans;//��obj������һϵ�еĲ���
    int arr[5000]={0},arr1[5000]={0},i=0,j=0,k,num=1;//arr����������Ԫ�أ�arr1��������ڵ�Ԫ��
     while(head!=NULL&&num<m){
        arr[i++]=head->val;
        head=head->next;
         num++;
    }
    while(head!=NULL&&num<=n){
        arr1[j++]=head->val;
        head=head->next;
         num++;
    }
    while(head!=NULL){
        arr[i++]=head->val;
        head=head->next;
        num++;
    }
    j--;
    k=i--;
    i=0;
    if(m==1){//�ж������Ƿ��1��ʼ
        obj->val=arr1[j--];
        while(j>=0){
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=arr1[j--];
            obj->next=temp;
            obj=obj->next;
        }
        while(i<k){
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=arr[i++];
            obj->next=temp;
            obj=obj->next;
        }
        obj->next=NULL;
    }
    else{
        obj->val=arr[i++];
        while(i<m-1){
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=arr[i++];
            obj->next=temp;
            obj=obj->next;
        }
        while(j>=0){
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=arr1[j--];
            obj->next=temp;
            obj=obj->next;
        }
        while(i<k){
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=arr[i++];
            obj->next=temp;
            obj=obj->next;
        }
        obj->next=NULL;
    }
    return ans;
}
