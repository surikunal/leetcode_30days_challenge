public class Solution {
    public ListNode detectCycle(ListNode head){
        if (head == null || head.next == null)
            return null;
        
        ListNode slow = head;
        ListNode fast = head;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast)
                break;
        }
        
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow.next;
                fast = fast.next;
            }
            return slow;
        }        
        return null;
    }
    
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;

        if (headA.next == null && headB.next == null) {
            if (headA.val == headB.val)
                return headA;
            else
                return null;
        }

        ListNode curr = headA;
        while (curr.next != null)
            curr = curr.next;

        curr.next = headA;
        ListNode rv = detectCycle(headB);
        curr.next = null;
        
        return rv;
    }
}