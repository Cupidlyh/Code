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
        obj->arr[i++]=head->val;//将head的节点值存到obj中的数组中
        head=head->next;
    }
    obj->num=i;//num是记录节点的总数量
    return obj;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
    int i,res=0;
    for(i=0;i<obj->num;i++){//从此处开始的两行是核心代码
        res=(rand()%(i+1)==0)?obj->arr[i]:res;//随机等概率取节点值
    }
    return res;
}

void solutionFree(Solution* obj) {
    free(obj);//释放
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/
