/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL || head -> next == NULL)//当无节点和只有一个节点时
        return head;
    struct ListNode *h = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *new_head = (struct ListNode *)malloc(sizeof(struct ListNode));
    h = head;
    int n = 1;
    while(head -> next != NULL) {
        head = head -> next;
        n++;
    }
    head -> next = h;//将原始链表连接成一个环
    int m = 1;
    while(h != NULL) {
        if(m == n - (k % n))//找到新的链表尾部
            break;
        m++;
        h = h -> next;
    }
    new_head = h -> next;//新的链表头部
    h -> next = NULL;
    return new_head;
}