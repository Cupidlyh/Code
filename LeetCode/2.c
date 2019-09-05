#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int arr1[10000]={0},arr2[10000]={0},res[10000]={0},a1=0,a2=0;//res�����Ǽ�¼��ӵĽ��
    while(l1!=NULL){//arr1����洢l1����Ľڵ�ֵ
        arr1[a1++]=l1->val;
        l1=l1->next;
    }
    while(l2!=NULL){//arr2����洢l2����Ľڵ�ֵ
        arr2[a2++]=l2->val;
        l2=l2->next;
    }
    int carry=0,i,len;//carry��¼��λ����
    len=a1>a2?a1:a2;//len��¼�������ֵ�λ��
    for(i=0;i<len+1;i++){//С��len+1��Ϊ�˷�ֹ��������Ӻ��ܵ��������ȱȳ������ֵ�λ����1λ
        if(arr1[i]+arr2[i]+carry>=10){//�ж��Ƿ��н�λ
            res[i]=(arr1[i]+arr2[i]+carry)%10;//��¼��ǰλ������
            carry=(arr1[i]+arr2[i]+carry)/10;//��¼��λ��
        }
        else{
            res[i]=arr1[i]+arr2[i]+carry;
            carry=0;//�޽�λ��ʱ��carryҪ��Ϊ0���ȴ����¼�¼�´ν�λֵ
        }
    }
    if(res[len]!=0)//�ж��Ƿ��ܳ��ȼ�1
        len=len+1;
    struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p=head;
    head->val=res[0];
    for(i=1;i<len;i++){//�����µķ�������
        struct ListNode *q=(struct ListNode *)malloc(sizeof(struct ListNode));
        q->val=res[i];
        p->next=q;
        p=p->next;
    }
    p->next=NULL;
    return head;
}
