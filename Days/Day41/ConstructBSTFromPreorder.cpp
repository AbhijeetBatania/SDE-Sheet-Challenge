// ------------------------------------------------------------
// Approach - Preorder + Upper Bound
// T.C : O(n)
// S.C : O(h)
//
// Idea:
// Use preorder traversal and a bound to construct the BST.
//
// Steps:
// 1. Take current preorder element as root.
// 2. Build left subtree with root->val as bound.
// 3. Build right subtree with previous bound.
// 4. Move idx forward whenever a node is created.
//
// Interview Notes:
// This avoids sorting and avoids explicitly finding the
// position of every element.
// ------------------------------------------------------------

class Solution {
public:
    int idx;

    TreeNode* build(vector<int>& preorder, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = build(preorder, root->val);
        root->right = build(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx = 0;
        return build(preorder, INT_MAX);
    }
};