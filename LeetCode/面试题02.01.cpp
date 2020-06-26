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
        unordered_set<int> s;//标记head中出现的元素
        ListNode* res = head;//结果节点
        ListNode* pre = head;//前节点
        ListNode* now = head -> next;//当前节点
        s.insert(pre -> val);//标记元素
        while(pre -> next != NULL) {
            if(s.find(now -> val) != s.end()) {//当前元素在链表中出现过
                pre -> next = now -> next;//删除此节点
                now = now -> next;
            }
            else {//没出现过，继续向下判断
                pre = pre -> next;
                now = now -> next;
                s.insert(pre -> val);
            }
        }
        return res;
    }
};
