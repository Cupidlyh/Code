/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> ll1,ll2;
        while(l1) {//压栈
            ll1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2) {//压栈
            ll2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int n1,n2,bit = 0;//bit记录进位信息
        struct ListNode *res = NULL;//结果链表的头指针
        while(!ll1.empty() && !ll2.empty()) {//都不为空
            n1 = ll1.top();
            ll1.pop();
            n2 = ll2.top();
            ll2.pop();
            struct ListNode *temp = new ListNode();
            temp -> val = (n1 + n2 + bit) % 10;
            bit = (n1 + n2 + bit) / 10;
            temp -> next = res;
            res = temp;
        }
        while(!ll1.empty()) {//ll1还有元素
            n1 = ll1.top();
            ll1.pop();
            struct ListNode *temp = new ListNode();
            temp -> val = (n1 + bit) % 10;
            bit = (n1 + bit) / 10;
            temp -> next = res;
            res = temp;
        }
        while(!ll2.empty()) {//ll2还有元素
            n2 = ll2.top();
            ll2.pop();
            struct ListNode *temp = new ListNode();
            temp -> val = (n2 + bit) % 10;
            bit = (n2 + bit) / 10;
            temp -> next = res;
            res = temp;
        }
        if(bit != 0) {//还存在进位
            struct ListNode *temp = new ListNode();
            temp -> val = bit;
            bit = 0;
            temp -> next = res;
            res = temp;
        }
        return res;
    }
};
