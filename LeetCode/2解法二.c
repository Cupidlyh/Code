/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *curr = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));//返回结果链表的头指针
    res = curr;
    int carry = 0;//记录进位
    while(l1 != NULL || l2 != NULL) {//循环条件
        int x = 0, y = 0;
        if(l1 != NULL) {
            x = l1 -> val;
            l1 = l1 -> next;
        }
        if(l2 != NULL){
            y = l2 -> val;
            l2 = l2 -> next;
        }
        curr -> val = (x + y + carry) % 10;//存储当前节点的值
        carry = (x + y + carry) / 10;//计算进位
        if(l1 == NULL && l2 == NULL)//两个链表都遍历完就跳出循环
            break;
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr -> next = temp;
        curr = curr -> next;
    }
    if(carry != 0) {//如果还有进位
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp -> val = carry;
        curr -> next = temp;
        curr = curr -> next;
    }
    curr -> next = NULL;
    return res;
}