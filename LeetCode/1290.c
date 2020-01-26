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
    while(head1) {//���������Ľڵ����
        num++;
        head1 = head1 -> next;
    }
    num--;//��Ϊ�������Ǵ�2��0���ݿ�ʼ�㣬����Ҫ��һ
    while(head) {
        sum = sum + (int)(pow(2,num) + 0.5) * head -> val;//��������ת��ʮ����
        num--;
        head = head -> next;
    }
    return sum;
}
