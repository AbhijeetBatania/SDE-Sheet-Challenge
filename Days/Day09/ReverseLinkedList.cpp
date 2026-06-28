/*
=========================================================
Problem: Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/
=========================================================
*/

// ---------------------------
// Method 1 : Iterative
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // Empty list or single node is already reversed.
        if (!head || !head->next)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {

            // Store the next node before breaking the link.
            next = curr->next;

            // Reverse the current node's pointer.
            curr->next = prev;

            // Move all pointers one step ahead.
            prev = curr;
            curr = next;
        }

        // 'prev' becomes the new head.
        return prev;
    }
};


// ---------------------------
// Method 2 : Recursion
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    ListNode* reverseSolve(ListNode* head) {

        // Base case:
        // Last node becomes the new head.
        if (!head || !head->next)
            return head;

        ListNode* newHead = reverseSolve(head->next);

        // Reverse the current link.
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    ListNode* reverseList(ListNode* head) {

        return reverseSolve(head);
    }
};