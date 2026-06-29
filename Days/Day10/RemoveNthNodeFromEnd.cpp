/*
=========================================================
Problem: Remove Nth Node From End of List
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
=========================================================
*/

// ---------------------------
// Method 1 : Reverse Linked List
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    // Reverse the linked list.
    ListNode* reverseSolve(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // If only one node exists,
        // deleting it results in an empty list.
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // Reverse the list to convert
        // "Nth from end" into "Nth from beginning".
        ListNode* reversed = reverseSolve(head);

        // Remove the first node in reversed list.
        if (n == 1) {

            reversed = reversed->next;
            return reverseSolve(reversed);
        }

        ListNode* temp = reversed;

        while (n > 2) {

            temp = temp->next;
            n--;
        }

        // Delete the required node.
        if (temp->next)
            temp->next = temp->next->next;

        // Reverse again to restore order.
        return reverseSolve(reversed);
    }
};


// ---------------------------
// Method 2 : Two Pointers (Optimal)
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Only one node present.
        if (!head->next)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Move fast pointer n steps ahead.
        while (n--) {

            fast = fast->next;
        }

        // Move both pointers together.
        while (fast) {

            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the head node.
        if (slow == head)
            return head->next;

        // Remove the required node.
        prev->next = slow->next;

        return head;
    }
};