/*
=========================================================
Problem: Palindrome Linked List
Link: https://leetcode.com/problems/palindrome-linked-list/
=========================================================
*/

// ---------------------------
// Method 1 : Reverse Second Half
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Reverse the linked list.
        while (curr) {

            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (!head || !head->next)
            return true;

        // Find the middle of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half.
        ListNode* second = reverse(slow);
        ListNode* first = head;

        // Compare both halves.
        while (second) {

            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};