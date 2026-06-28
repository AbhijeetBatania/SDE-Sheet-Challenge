/*
=========================================================
Problem: Middle of the Linked List
Link: https://leetcode.com/problems/middle-of-the-linked-list/
=========================================================
*/

// ---------------------------
// Method 1 : Slow and Fast Pointer
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Slow moves one step,
        // Fast moves two steps.
        while (fast->next && fast->next->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // For even length,
        // return the second middle node.
        return fast->next ? slow->next : slow;
    }
};