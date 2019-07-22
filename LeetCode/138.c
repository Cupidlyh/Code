#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;

        //第一步，复制原始的节点，连接自身后面
        Node* p=head;
        while(p){
            Node *q=(Node *)malloc(sizeof(Node));
            q->val=p->val;//给新建的节点赋值
            q->next=p->next;
            p->next=q;
            p=q->next;
        }

        //第二步，将添加的节点random 链接到原始节点random的下一个位置
        Node* p1=head;
        while(p1){
            Node* q=p1->next;
            if(p1->random==NULL)
                q->random=NULL;
            else
                q->random=p1->random->next;
            p1=q->next;//处理下一个节点
        }

        //第三步，恢复原始链表，得到新链表
        Node* p2=head;
        Node* copy=head->next;
        Node* copy1=head->next;
        while(p2->next->next!=NULL){
            p2->next=copy->next;
            p2=copy->next;
            copy->next=p2->next;
            copy=p2->next;
        }
        p2->next=NULL;
        copy->next=NULL;
        return copy1;
    }
};
