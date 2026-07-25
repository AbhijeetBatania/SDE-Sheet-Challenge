// Approach : Recursive DFS
// T.C : O(n)
// S.C : O(h)

class Solution {
  public:

    bool solve(Node *root) {

        // Empty tree or leaf node satisfies property
        if (root == NULL ||
            (root->left == NULL && root->right == NULL))
            return true;

        int left = 0;
        int right = 0;

        // Left child value
        if (root->left)
            left = root->left->data;

        // Right child value
        if (root->right)
            right = root->right->data;

        // Property violated
        if (root->data != left + right)
            return false;

        // Check recursively
        return solve(root->left) &&
               solve(root->right);
    }

    bool isSumProperty(Node *root) {

        return solve(root);
    }
};