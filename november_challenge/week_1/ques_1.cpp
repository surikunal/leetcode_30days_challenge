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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* forw = nullptr;
        ListNode* prev = nullptr;
        
        while (curr != nullptr) {
            forw = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    int getDecimalValue(ListNode* head) {
        ListNode* nhead = reverse(head);
        
        int ans = 0;
        int mult = 1;
        while (nhead != nullptr) {
            ans += (nhead->val * mult);
            mult *= 2;
            nhead = nhead->next;
        }
        return ans;
    }
};