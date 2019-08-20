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
    struct ListNode* ans=head;//ans�����
    if(ans==NULL||ans->next==NULL)//������ֻ��һ���ڵ���޽ڵ�ʱ
        return ans;
    int temp;
    while(ans->next!=NULL&&ans->val==ans->next->val){//��whileѭ���������ǽ������˵��ظ�Ԫ��ɾ��
        temp=ans->val;
        while(ans!=NULL&&ans->val==temp)
            ans=ans->next;
        if(ans==NULL||ans->next==NULL)
            return ans;
    }
    struct ListNode* l1=(struct ListNode* )malloc(sizeof(struct ListNode));//ͷ�ڵ㣬ָ��ans
    l1->next=ans;
    struct ListNode* l2=ans;
    struct ListNode* l3=ans->next;
    while(l3!=NULL){
        if(l2->val==l3->val){//������
            while(l3!=NULL&&l2->val==l3->val){//��whileѭ��������l2Ϊ�ҵ��ظ����ֵ����������ֵ�λ��
                l2=l2->next;
                l3=l3->next;
            }
            if(l3!=NULL){//�ظ�Ԫ�������ֵ�λ�ò�������β��ʱ
                l2=l2->next;
                l3=l3->next;
                l1->next=l2;
            }
            else//����ظ�Ԫ�������ֵ�λ���������β��ʱ
                l1->next=NULL;
        }
        else{//�����ʱ������ڵ�����
            l1=l1->next;
            l2=l2->next;
            l3=l3->next;
        }
    }
    return ans;
}
