// Approach : Recursive Height Calculation
// T.C : O(n)
// S.C : O(h)

class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Empty tree has height 0
        if (root == NULL)
            return 0;

        // Height of current node =
        // 1 + maximum height of left and right subtree
        int depth = 1 + max(maxDepth(root->left), maxDepth(root->right));

        return depth;
    }
};