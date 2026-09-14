// ------------------------------------------------------------
// Approach 1 - Recursive BST Search
// T.C : O(h)
// S.C : O(h)
//
// Idea:
// Use the BST property to decide whether to move left or right.
//
// Steps:
// 1. If root is NULL, value doesn't exist.
// 2. If root->val == val, return root.
// 3. If val is smaller, search left.
// 4. Otherwise, search right.
//
// Interview Notes:
// In a balanced BST, h = O(log n).
// In a skewed BST, h = O(n).
// ------------------------------------------------------------

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val)
            return root;

        if (val < root->val)
            return searchBST(root->left, val);

        return searchBST(root->right, val);
    }
};



// ------------------------------------------------------------
// Approach 2 - Iterative BST Search
// T.C : O(h)
// S.C : O(1)
//
// Idea:
// Traverse the BST using a while loop instead of recursion.
//
// Steps:
// 1. Start from root.
// 2. If value is found, return the node.
// 3. If val is smaller, move to left.
// 4. Otherwise, move to right.
// 5. If root becomes NULL, value doesn't exist.
//
// Interview Notes:
// Iterative approach avoids recursive stack space.
// ------------------------------------------------------------

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if (root->val == val)
                return root;

            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }

        return nullptr;
    }
};