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
        while(l1) {//ѹջ
            ll1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while(l2) {//ѹջ
            ll2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int n1,n2,bit = 0;//bit��¼��λ��Ϣ
        struct ListNode *res = NULL;//��������ͷָ��
        while(!ll1.empty() && !ll2.empty()) {//����Ϊ��
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
        while(!ll1.empty()) {//ll1����Ԫ��
            n1 = ll1.top();
            ll1.pop();
            struct ListNode *temp = new ListNode();
            temp -> val = (n1 + bit) % 10;
            bit = (n1 + bit) / 10;
            temp -> next = res;
            res = temp;
        }
        while(!ll2.empty()) {//ll2����Ԫ��
            n2 = ll2.top();
            ll2.pop();
            struct ListNode *temp = new ListNode();
            temp -> val = (n2 + bit) % 10;
            bit = (n2 + bit) / 10;
            temp -> next = res;
            res = temp;
        }
        if(bit != 0) {//�����ڽ�λ
            struct ListNode *temp = new ListNode();
            temp -> val = bit;
            bit = 0;
            temp -> next = res;
            res = temp;
        }
        return res;
    }
};
