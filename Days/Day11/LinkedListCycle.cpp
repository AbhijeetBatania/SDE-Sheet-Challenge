/*
=========================================================
Problem: Linked List Cycle
Link: https://leetcode.com/problems/linked-list-cycle/
=========================================================
*/

// ---------------------------
// Method 1 : Floyd's Cycle Detection
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    bool hasCycle(ListNode* head) {

        if (!head)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        // Slow moves one step,
        // Fast moves two steps.
        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected.
            if (slow == fast)
                return true;
        }

        return false;
    }
};