#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
    struct ListNode *PA = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *PB = (struct ListNode *)malloc(sizeof(struct ListNode));
    PA = headA;
    PB = headB;
    while(PA != PB) {
        PA = (PA == NULL) ? headB : PA -> next;//�����Լ���·������һ�������·
        PB = (PB == NULL) ? headA : PB -> next;//���������߹��ĳ�����һ���ģ�����н�����һ�����ڽ��㴦����
    }
    return PA;
}
