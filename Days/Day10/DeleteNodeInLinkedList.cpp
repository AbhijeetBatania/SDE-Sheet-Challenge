/*
=========================================================
Problem: Delete Node in a Linked List
Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
=========================================================
*/

// ---------------------------
// Method 1 : Copy Next Node
// Time Complexity: O(1)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    void deleteNode(ListNode* node) {

        // Copy the value of the next node.
        node->val = node->next->val;

        // Skip the next node.
        node->next = node->next->next;
    }
};