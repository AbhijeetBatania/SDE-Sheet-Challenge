// ------------------------------------------------------------
// Approach - Iterative BST Traversal
// T.C : O(h)
// S.C : O(1)
//
// Idea:
// Find the largest value <= k.
//
// Steps:
// 1. If current value equals k, return k.
// 2. If current value is smaller than k, store it as answer
//    and move right to find a potentially larger value.
// 3. If current value is greater than k, move left.
//
// Interview Notes:
// This is essentially finding the floor of k in a BST.
// ------------------------------------------------------------

class Solution {
public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;

        while (root != nullptr) {
            if (root->data == k) {
                return k;
            }

            if (root->data < k) {
                ans = root->data;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return ans;
    }
};