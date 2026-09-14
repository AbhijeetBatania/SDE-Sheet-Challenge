// ------------------------------------------------------------
// Approach - Iterative BST Traversal
// T.C : O(h)
// S.C : O(1)
//
// Idea:
// Find the smallest value >= x.
//
// Steps:
// 1. If current value equals x, return x.
// 2. If current value is greater than x, store it as answer
//    and move left to find a smaller valid value.
// 3. If current value is smaller than x, move right.
//
// Interview Notes:
// This is essentially finding the ceil of x in a BST.
// ------------------------------------------------------------

class Solution {
public:
    int findCeil(Node* root, int x) {
        int ans = -1;

        while (root != nullptr) {
            if (root->data == x) {
                return x;
            }

            if (root->data > x) {
                ans = root->data;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return ans;
    }
};