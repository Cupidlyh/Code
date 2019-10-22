#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* sortList(struct ListNode* head){
    if(head == NULL || head -> next == NULL)//当无节点或只有一个节点时
        return head;
    struct ListNode *Thead = (struct ListNode *)malloc(sizeof(struct ListNode));//头节点
    struct ListNode *a = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *b = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *c = (struct ListNode *)malloc(sizeof(struct ListNode));
    Thead -> next = head;
    a = head;
    b = Thead;
    while(a && a -> next && a -> val <= a -> next -> val)//最开始如果有一段是有升序排序的就跳过去
        a = a -> next;
    c = a -> next;
    while(c) {//c节点为当前要进行插入排序的节点
        a -> next = c -> next;//因为c节点被拿出了，所以a要与c后面的点连接上
        while(b -> next && b -> next -> val < c -> val)//找到c要插入的位置
            b = b -> next;
        c -> next = b -> next;
        b -> next = c;
        b = Thead;//b重置以便下次寻找插入位置
        while(a && a -> next && a -> val <= a -> next -> val)//a与c后面的点重接后如果有一段升序排序就跳过
            a = a -> next;
        c = a -> next;
    }
    return Thead -> next;
}
