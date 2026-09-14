// ------------------------------------------------------------
// Approach - Inorder Traversal
// T.C : O(n)
// S.C : O(h)
//
// Idea:
// Inorder traversal of BST produces sorted order.
// Therefore, kth visited node is the kth smallest element.
//
// Steps:
// 1. Traverse left subtree.
// 2. Decrease k when visiting root.
// 3. If k becomes 0, store the answer.
// 4. Traverse right subtree.
//
// Interview Notes:
// BST + kth smallest -> think INORDER.
// ------------------------------------------------------------

class Solution {
public:
    int ans;

    void inorder(TreeNode* root, int& k) {
        if (root == nullptr)
            return;

        inorder(root->left, k);

        k--;

        if (k == 0) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};