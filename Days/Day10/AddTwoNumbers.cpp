/*
=========================================================
Problem: Add Two Numbers
Link: https://leetcode.com/problems/add-two-numbers/
=========================================================
*/

// ---------------------------
// Method 1 : Simulation
// Time Complexity: O(max(M, N))
// Space Complexity: O(max(M, N))
// ---------------------------

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;

        // Dummy node simplifies insertion.
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (l1 || l2) {

            int sum = carry;

            // Add value from first list.
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from second list.
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Store current digit.
            tail->next = new ListNode(sum % 10);

            carry = sum / 10;

            tail = tail->next;
        }

        // If carry still exists,
        // create one more node.
        if (carry)
            tail->next = new ListNode(carry);

        return dummy->next;
    }
};