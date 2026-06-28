/*
=========================================================
Problem: Merge Two Sorted Lists
Link: https://leetcode.com/problems/merge-two-sorted-lists/
=========================================================
*/

// ---------------------------
// Method 1 : Iterative
// Time Complexity: O(M + N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1,
                            ListNode* list2) {

        // Dummy node simplifies insertion.
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode* head1 = list1;
        ListNode* head2 = list2;

        // Merge while both lists contain nodes.
        while (head1 && head2) {

            if (head1->val <= head2->val) {

                tail->next = head1;
                head1 = head1->next;
            }
            else {

                tail->next = head2;
                head2 = head2->next;
            }

            tail = tail->next;
        }

        // Attach the remaining nodes.
        if (head1)
            tail->next = head1;

        if (head2)
            tail->next = head2;

        return dummy->next;
    }
};