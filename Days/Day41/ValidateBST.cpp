// ------------------------------------------------------------
// Approach - Range / Boundary Checking
// T.C : O(n)
// S.C : O(h)
//
// Idea:
// Every node must lie within a valid range.
//
// Steps:
// 1. Start root with (-∞, +∞).
// 2. For left child, upper bound becomes root->val.
// 3. For right child, lower bound becomes root->val.
// 4. If any node violates its range, return false.
//
// Interview Notes:
// Use long long instead of int for safe boundary handling.
// ------------------------------------------------------------

class Solution {
public:
    bool check(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr)
            return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};