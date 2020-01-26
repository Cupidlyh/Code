#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    struct ListNode * head1 = head;
    int num = 0,sum = 0;
    while(head1) {//计算出链表的节点个数
        num++;
        head1 = head1 -> next;
    }
    num--;//因为二进制是从2的0次幂开始算，所以要减一
    while(head) {
        sum = sum + (int)(pow(2,num) + 0.5) * head -> val;//将二进制转成十进制
        num--;
        head = head -> next;
    }
    return sum;
}
