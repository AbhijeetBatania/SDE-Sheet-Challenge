// ------------------------------------------------------------
// Approach - Reverse Inorder Traversal
// T.C : O(n)
// S.C : O(h)
//
// Idea:
// Reverse inorder traversal of BST gives elements in
// descending order.
//
// Steps:
// 1. Traverse right subtree.
// 2. Decrease k when visiting root.
// 3. If k becomes 0, store the answer.
// 4. Traverse left subtree.
//
// Interview Notes:
// BST + kth largest -> think REVERSE INORDER.
// ------------------------------------------------------------

class Solution {
  public:
    int ans;

    void inorder(Node* root, int& k) {
        if (root == nullptr)
            return;

        // Reverse inorder: Right -> Root -> Left
        inorder(root->right, k);

        k--;

        if (k == 0) {
            ans = root->data;
            return;
        }

        inorder(root->left, k);
    }

    int kthLargest(Node *root, int k) {
        ans = -1;
        inorder(root, k);
        return ans;
    }
};