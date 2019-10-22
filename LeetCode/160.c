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
        PA = (PA == NULL) ? headB : PA -> next;//先走自己的路再走另一个链表的路
        PB = (PB == NULL) ? headA : PB -> next;//这样二者走过的长度是一样的，如果有交点则一定会在交点处相遇
    }
    return PA;
}
