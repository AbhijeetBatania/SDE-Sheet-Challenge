// ------------------------------------------------------------
// Approach - BST Traversal
// T.C : O(h)
// S.C : O(1)
//
// Idea:
// Find predecessor and successor using BST ordering.
//
// Predecessor:
// Largest value smaller than key.
//
// Successor:
// Smallest value greater than key.
//
// Steps:
// 1. Traverse BST to find predecessor.
// 2. Traverse BST again to find successor.
// 3. Return both nodes.
//
// Interview Notes:
// Predecessor moves right when curr->data < key.
// Successor moves left when curr->data > key.
// ------------------------------------------------------------

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = nullptr;
        Node* suc = nullptr;

        Node* curr = root;

        // Find predecessor
        while (curr != nullptr) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        curr = root;

        // Find successor
        while (curr != nullptr) {
            if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        return {pre, suc};
    }
};