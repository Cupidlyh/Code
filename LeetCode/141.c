#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL)
        return false;
    struct ListNode *slow=head;//慢指针
    struct ListNode *fast=head->next;//快指针
    while(slow!=fast){
        if(fast==NULL||fast->next==NULL)
            return false;
        slow=slow->next;
        fast=fast->next->next;//快指针每次比慢指针多走一步
    }
    return true;
}
