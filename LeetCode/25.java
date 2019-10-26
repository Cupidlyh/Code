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
        while (curr != b) {//反转链表
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;//返回反转后的头结点
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null) 
            return head;
        ListNode a,b;
        a = head;
        b = head;
        for(int i = 0; i < k; i++) {
            if(b == null)//当不满足k个时，不需要反转
                return head;
            b = b.next;
        }
        ListNode newHead = reverse(a,b);//先反转前k个
        a.next = reverseKGroup(b,k);//然后通过递归继续反转后面的链表，并将链表连接起来
        return newHead;
    }
}
