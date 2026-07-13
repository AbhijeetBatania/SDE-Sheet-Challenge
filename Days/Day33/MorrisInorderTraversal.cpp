// ------------------------------------------------------------
// Morris Inorder Traversal
// T.C : O(n)
// S.C : O(1)
//
// Idea:
// Morris Traversal performs inorder traversal without using
// recursion or an explicit stack.
//
// It temporarily creates a thread from the inorder predecessor
// to the current node.
//
// Steps:
// 1. If left child doesn't exist:
//      - Visit current node.
//      - Move to right child.
// 2. Otherwise:
//      - Find inorder predecessor.
//      - If thread doesn't exist:
//            create thread and move left.
//      - Else:
//            remove thread,
//            visit current node,
//            move right.
//
// The original tree structure is restored before the algorithm
// finishes.
// ------------------------------------------------------------

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;

                while (pred->right != NULL && pred->right != curr)
                    pred = pred->right;

                if (pred->right == NULL) {
                    // create thread
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    // remove thread
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};