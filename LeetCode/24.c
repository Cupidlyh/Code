#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *Thead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *a = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *b = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *c = (struct ListNode *)malloc(sizeof(struct ListNode));
    Thead -> next = head;
    c = Thead;
    while(c -> next && c -> next -> next) {
        a = c -> next;
        b = c -> next -> next;
        c -> next = b;
        a -> next = b -> next;
        b -> next = a;
        c = c -> next -> next;
    }
    return Thead -> next;
}
