#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)
        return 0;
    int i;
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));//每次找插入位置的节点
    struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));//头节点
    head -> next = lists[0];
    temp = head;
    for(i = 1; i < listsSize; i++) {//遍历其余链表
        while(lists[i]) {//遍历当前链表的每一个节点
        while(temp -> next && temp -> next -> val <= lists[i] -> val)//找到插入的位置
            temp = temp -> next;
        next = lists[i] -> next;//记录下此节点的下一个节点
        lists[i] -> next = temp -> next;
        temp -> next = lists[i];
        lists[i] = next;//将此节点的下一个位置赋给它
        temp = head;//重置temp以便下次继续寻找插入位置
        }
    }
    return head -> next;
}
