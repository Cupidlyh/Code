#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    int arr[50000];
    int num;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */

Solution* solutionCreate(struct ListNode* head) {
    Solution *obj=(Solution *)malloc(sizeof(Solution));
    int i=0;
    while(head!=NULL){
        obj->arr[i++]=head->val;//��head�Ľڵ�ֵ�浽obj�е�������
        head=head->next;
    }
    obj->num=i;//num�Ǽ�¼�ڵ��������
    return obj;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    int i,res=0;
    for(i=0;i<obj->num;i++){//�Ӵ˴���ʼ�������Ǻ��Ĵ���
        res=(rand()%(i+1)==0)?obj->arr[i]:res;//����ȸ���ȡ�ڵ�ֵ
    }
    return res;
}

void solutionFree(Solution* obj) {
    free(obj);//�ͷ�
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/
