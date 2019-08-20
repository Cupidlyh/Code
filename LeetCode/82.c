#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* ans=head;//ans是最后
    if(ans==NULL||ans->next==NULL)//当链表只有一个节点和无节点时
        return ans;
    int temp;
    while(ans->next!=NULL&&ans->val==ans->next->val){//此while循环的作用是将链表开端的重复元素删掉
        temp=ans->val;
        while(ans!=NULL&&ans->val==temp)
            ans=ans->next;
        if(ans==NULL||ans->next==NULL)
            return ans;
    }
    struct ListNode* l1=(struct ListNode* )malloc(sizeof(struct ListNode));//头节点，指向ans
    l1->next=ans;
    struct ListNode* l2=ans;
    struct ListNode* l3=ans->next;
    while(l3!=NULL){
        if(l2->val==l3->val){//如果相等
            while(l3!=NULL&&l2->val==l3->val){//此while循环结束后l2为找到重复出现的数字最后出现的位置
                l2=l2->next;
                l3=l3->next;
            }
            if(l3!=NULL){//重复元素最后出现的位置不在链表尾部时
                l2=l2->next;
                l3=l3->next;
                l1->next=l2;
            }
            else//如果重复元素最后出现的位置在链表的尾部时
                l1->next=NULL;
        }
        else{//不相等时，链表节点下移
            l1=l1->next;
            l2=l2->next;
            l3=l3->next;
        }
    }
    return ans;
}
