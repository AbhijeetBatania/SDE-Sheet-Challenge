/*
=========================================================
Problem: Flattening a Linked List
Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
=========================================================
*/

// ---------------------------
// Method 1 : Recursion + Merge
// Time Complexity: O(N × M × N)
// Space Complexity: O(N × M) (Recursive Stack)
// ---------------------------

Node *merge(Node* head1,Node* head2)
{
    // Handle base cases.
    if(!head1 && !head2) return nullptr;
    else if(!head1) return head2;
    else if(!head2) return head1;

    Node* dummy = new Node(0);
    Node* temp = dummy;

    // Merge two sorted bottom lists.
    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            temp->bottom = head1;
            head1 = head1->bottom;
        }
        else
        {
            temp->bottom = head2;
            head2 = head2->bottom;
        }

        temp = temp->bottom;
    }

    // Attach remaining nodes.
    if(head1){
        temp->bottom = head1;
        temp = temp->bottom;
    }

    if(head2){
        temp->bottom = head2;
        temp = temp->bottom;
    }

    return dummy->bottom;
}

class Solution {
public:

    Node *flatten(Node *root) {

        if(!root)
            return nullptr;

        // Flatten the remaining linked list.
        Node* root2 = flatten(root->next);

        // Merge the current list with the flattened list.
        return merge(root, root2);
    }
};