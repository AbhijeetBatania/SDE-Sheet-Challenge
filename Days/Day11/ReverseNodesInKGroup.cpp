/*
=========================================================
Problem: Reverse Nodes in k-Group
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
=========================================================
*/

// ---------------------------
// Method 1 : Reverse Each Group
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    // Reverse a linked list.
    ListNode* reverseLinkedList(ListNode* head) {

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

    // Return the kth node from current position.
    ListNode* getKthNode(ListNode* temp, int k) {

        while (temp && k > 1) {

            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp) {

            // Find kth node.
            ListNode* kthNode = getKthNode(temp, k);

            // Less than k nodes remain.
            if (!kthNode) {

                if (prevLast)
                    prevLast->next = temp;

                break;
            }

            // Store next group's head.
            ListNode* nextGroup = kthNode->next;

            // Detach current group.
            kthNode->next = nullptr;

            // Reverse current group.
            ListNode* newHead = reverseLinkedList(temp);

            // Connect previous group.
            if (temp == head)
                head = newHead;
            else
                prevLast->next = newHead;

            // Current head becomes last node.
            prevLast = temp;

            // Continue with next group.
            temp = nextGroup;
        }

        return head;
    }
};