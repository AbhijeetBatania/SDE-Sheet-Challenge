// Approach : Calculate height while updating diameter
// T.C : O(n)
// S.C : O(h)

class Solution {
public:

    // Returns height of current subtree
    int height(TreeNode* root , int & diameter) {

        // Empty subtree has height 0
        if (root == nullptr)
            return 0;

        // Height of left subtree
        int left = height(root->left, diameter);

        // Height of right subtree
        int right = height(root->right, diameter);

        // Diameter passing through current node
        diameter = max(diameter, left + right);

        // Return height of current subtree
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;

        height(root, diameter);

        return diameter;
    }
};