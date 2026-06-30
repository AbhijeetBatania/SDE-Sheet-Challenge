/*
=========================================================
Problem: Linked List Cycle II
Link: https://leetcode.com/problems/linked-list-cycle-ii/
=========================================================
*/

// ---------------------------
// Method 1 : Floyd's Cycle Detection
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(!head || !head->next)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Detect whether a cycle exists.
        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow)
                break;
        }

        // No cycle found.
        if(fast != slow)
            return NULL;

        // Move one pointer to the head.
        ListNode* start = head;

        // Both pointers move one step at a time.
        // Their meeting point is the starting node of the cycle.
        while(slow != start){

            slow = slow->next;
            start = start->next;
        }

        return start;
    }
};