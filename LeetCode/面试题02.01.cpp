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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        unordered_set<int> s;//���head�г��ֵ�Ԫ��
        ListNode* res = head;//����ڵ�
        ListNode* pre = head;//ǰ�ڵ�
        ListNode* now = head -> next;//��ǰ�ڵ�
        s.insert(pre -> val);//���Ԫ��
        while(pre -> next != NULL) {
            if(s.find(now -> val) != s.end()) {//��ǰԪ���������г��ֹ�
                pre -> next = now -> next;//ɾ���˽ڵ�
                now = now -> next;
            }
            else {//û���ֹ������������ж�
                pre = pre -> next;
                now = now -> next;
                s.insert(pre -> val);
            }
        }
        return res;
    }
};
