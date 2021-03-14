/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (k-- > 1) {
            fast = fast->next;
        }
        ListNode* a = fast;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* b = slow;
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
        return head;
    }
};