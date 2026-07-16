// Approach-1 : Height calculation using boolean flag
// T.C : O(n)
// S.C : O(h)

class Solution {
public:

    // Returns height and updates balance status
    int height(TreeNode* root , bool & balanced) {

        // Empty subtree
        if (root == nullptr)
            return 0;

        // Height of left subtree
        int left = height(root->left, balanced);

        // Height of right subtree
        int right = height(root->right, balanced);

        // If difference becomes greater than 1,
        // tree is not height balanced
        if(abs(left - right) > 1){
            balanced = false;
        }

        // Return current subtree height
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {

        if(root == NULL)
            return true;

        bool balanced = true;

        height(root, balanced);

        return balanced;
    }
};


// Approach-2 : Optimized Height Calculation
// T.C : O(n)
// S.C : O(h)

class Solution {
public:

    // Returns height if balanced,
    // otherwise returns -1
    int height(TreeNode* root) {

        // Empty tree
        if (root == NULL)
            return 0;

        // Check left subtree
        int left = height(root->left);

        // If left subtree is unbalanced
        if (left == -1)
            return -1;

        // Check right subtree
        int right = height(root->right);

        // If right subtree is unbalanced
        if (right == -1)
            return -1;

        // Current node is unbalanced
        if (abs(left - right) > 1)
            return -1;

        // Return height
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {

        return height(root) != -1;
    }
};