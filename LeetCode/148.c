#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* sortList(struct ListNode* head){
    if(head == NULL || head -> next == NULL)//���޽ڵ��ֻ��һ���ڵ�ʱ
        return head;
    struct ListNode *Thead = (struct ListNode *)malloc(sizeof(struct ListNode));//ͷ�ڵ�
    struct ListNode *a = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *b = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *c = (struct ListNode *)malloc(sizeof(struct ListNode));
    Thead -> next = head;
    a = head;
    b = Thead;
    while(a && a -> next && a -> val <= a -> next -> val)//�ʼ�����һ��������������ľ�����ȥ
        a = a -> next;
    c = a -> next;
    while(c) {//c�ڵ�Ϊ��ǰҪ���в�������Ľڵ�
        a -> next = c -> next;//��Ϊc�ڵ㱻�ó��ˣ�����aҪ��c����ĵ�������
        while(b -> next && b -> next -> val < c -> val)//�ҵ�cҪ�����λ��
            b = b -> next;
        c -> next = b -> next;
        b -> next = c;
        b = Thead;//b�����Ա��´�Ѱ�Ҳ���λ��
        while(a && a -> next && a -> val <= a -> next -> val)//a��c����ĵ��ؽӺ������һ���������������
            a = a -> next;
        c = a -> next;
    }
    return Thead -> next;
}
