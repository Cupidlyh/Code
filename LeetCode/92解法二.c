/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swap(struct ListNode* head,struct ListNode* tail){//反转所给区间内的链表
    struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *curr = (struct ListNode *)malloc(sizeof(struct ListNode));
    curr = head;//curr指针指向当前要进行操作的节点
    prev = NULL;//prev为curr前面的一个节点
    while(head != NULL) {//循环终止条件
        head = head -> next;
        curr -> next = prev;
        prev = curr;
        curr = head;
    }
    return prev;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    int m1 = 1;//m1记录链表遍历的位置
    struct ListNode *h = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *h1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *t1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1 = head;
    while(head != NULL) {//遍历链表来找出所要反转的链表区间
        if(m1 + 1 == m)
            h1 = head;//记录下m位置前一个的节点
        if(m1 == m)
            h = head;
        if(m1 == n) {
            t = head;
            t1 = head -> next;//记录n位置后一个的节点
            t -> next = NULL;
            break;
        }
        head = head -> next;
        m1++;
    }
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = swap(h,t);//反转m到n区间的链表
    h1 -> next = temp;//将反转后的链表重新连接到原链表的位置上
    h -> next = t1;
    if(m == 1)//判断是否从第一个节点开始反转链表
        head1 = temp;
    return head1;
}