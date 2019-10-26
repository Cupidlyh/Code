package leetcode25;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class Solution {
	public ListNode reverse(ListNode a,ListNode b) {
        ListNode prev = null,curr = a,next = a;
        while (curr != b) {//��ת����
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;//���ط�ת���ͷ���
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null) 
            return head;
        ListNode a,b;
        a = head;
        b = head;
        for(int i = 0; i < k; i++) {
            if(b == null)//��������k��ʱ������Ҫ��ת
                return head;
            b = b.next;
        }
        ListNode newHead = reverse(a,b);//�ȷ�תǰk��
        a.next = reverseKGroup(b,k);//Ȼ��ͨ���ݹ������ת�������������������������
        return newHead;
    }
}
