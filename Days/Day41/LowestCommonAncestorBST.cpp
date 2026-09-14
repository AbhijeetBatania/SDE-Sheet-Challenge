// ------------------------------------------------------------
// Approach - Iterative BST Property
// T.C : O(h)
// S.C : O(1)
//
// Idea:
// Use BST ordering to decide whether LCA is on the left,
// right, or current node.
//
// Steps:
// 1. If both p and q are smaller, go left.
// 2. If both are greater, go right.
// 3. Otherwise current root is the LCA.
//
// Interview Notes:
// This is better than generic Binary Tree LCA because we
// exploit the BST property.
// ------------------------------------------------------------

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }

        return nullptr;
    }
};