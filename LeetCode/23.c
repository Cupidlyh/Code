#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return 0;
    int i;
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));//ÿ���Ҳ���λ�õĽڵ�
    struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));//ͷ�ڵ�
    head -> next = lists[0];
    temp = head;
    for(i = 1; i < listsSize; i++) {//������������
        while(lists[i]) {//������ǰ�����ÿһ���ڵ�
        while(temp -> next && temp -> next -> val <= lists[i] -> val)//�ҵ������λ��
            temp = temp -> next;
        next = lists[i] -> next;//��¼�´˽ڵ����һ���ڵ�
        lists[i] -> next = temp -> next;
        temp -> next = lists[i];
        lists[i] = next;//���˽ڵ����һ��λ�ø�����
        temp = head;//����temp�Ա��´μ���Ѱ�Ҳ���λ��
        }
    }
    return head -> next;
}
