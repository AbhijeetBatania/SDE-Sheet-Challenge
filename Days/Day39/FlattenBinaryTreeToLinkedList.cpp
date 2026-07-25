// Approach : Reverse Preorder Traversal
// T.C : O(n)
// S.C : O(h)

class Solution {
public:

    // Stores previously processed node
    TreeNode* prev = NULL;

    void solve(TreeNode* root) {

        // Base Case
        if (root == NULL)
            return;

        // Process right subtree first
        solve(root->right);

        // Process left subtree
        solve(root->left);

        // Connect current node to previous node
        root->right = prev;

        // Left child becomes NULL
        root->left = NULL;

        // Update previous node
        prev = root;
    }

    void flatten(TreeNode* root) {

        solve(root);
    }
};