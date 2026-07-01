/*
=========================================================
Problem: Rotate List
Link: https://leetcode.com/problems/rotate-list/
=========================================================
*/

// ---------------------------
// Method 1 : Find Length + Break & Connect
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Base cases.
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* temp = head;
        int n = 1;

        // Find the length of the linked list.
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Rotating by a multiple of length
        // gives the same linked list.
        k = k % n;

        if (k == 0)
            return head;

        // Find the new last node.
        int steps = n - k;

        ListNode* start = head;

        while (steps > 1) {
            start = start->next;
            steps--;
        }

        // Store the new head.
        ListNode* nextNode = start->next;

        // Break the list.
        start->next = nullptr;

        // Connect the old tail to the old head.
        temp->next = head;

        return nextNode;
    }
};