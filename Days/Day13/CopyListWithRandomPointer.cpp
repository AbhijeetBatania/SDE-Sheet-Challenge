/*
=========================================================
Problem: Copy List with Random Pointer
Link: https://leetcode.com/problems/copy-list-with-random-pointer/
=========================================================
*/

// ---------------------------
// Method 1 : Hash Map
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* dummy = new Node(0);

        // Stores mapping :
        // Original Node -> Copied Node
        unordered_map<Node*, Node*> mp;

        Node* temp1 = head;
        Node* temp2 = dummy;

        // First pass:
        // Create a copy of every node.
        while(temp1){

            temp2->next = new Node(temp1->val);

            temp2 = temp2->next;

            mp[temp1] = temp2;

            temp1 = temp1->next;
        }

        temp1 = head;

        // Second pass:
        // Assign random pointers.
        while(temp1){

            if(temp1->random == nullptr)
                mp[temp1]->random = nullptr;

            else
                mp[temp1]->random = mp[temp1->random];

            temp1 = temp1->next;
        }

        return dummy->next;
    }
};