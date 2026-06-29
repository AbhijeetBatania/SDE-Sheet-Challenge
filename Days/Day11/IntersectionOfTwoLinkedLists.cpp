/*
=========================================================
Problem: Intersection of Two Linked Lists
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
=========================================================
*/

// ---------------------------
// Method 1 : Brute Force
// Time Complexity: O(M × N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* tempA = headA;

        // Compare every node of list A
        // with every node of list B.
        while (tempA) {

            ListNode* tempB = headB;

            while (tempB) {

                if (tempA == tempB)
                    return tempA;

                tempB = tempB->next;
            }

            tempA = tempA->next;
        }

        return nullptr;
    }
};


// ---------------------------
// Method 2 : Hash Set
// Time Complexity: O(M + N)
// Space Complexity: O(M)
// ---------------------------

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA,
                                  ListNode* headB) {

        unordered_set<ListNode*> visited;

        // Store all nodes of first list.
        while (headA) {

            visited.insert(headA);
            headA = headA->next;
        }

        // First common node is the answer.
        while (headB) {

            if (visited.count(headB))
                return headB;

            headB = headB->next;
        }

        return nullptr;
    }
};


// ---------------------------
// Method 3 : Two Pointer (Optimal)
// Time Complexity: O(M + N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA,
                                  ListNode* headB) {

        if (!headA || !headB)
            return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        // After traversing both lists,
        // both pointers travel equal distance.
        while (pA != pB) {

            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};