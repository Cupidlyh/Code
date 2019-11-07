/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *curr = (struct ListNode *)malloc(sizeof(struct ListNode));
    curr = head;//curr指针指向当前要进行操作的节点
    prev = NULL;//prev为curr前面的一个节点
    while(head != NULL) {//循环终止条件
        head = head -> next;
        curr -> next = prev;
        prev = curr;
        curr = head;
    }
    return prev;
}