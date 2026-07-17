// Approach : Recursive DFS
// T.C : O(n)
// S.C : O(h)

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If either node is NULL
        if (p == NULL || q == NULL)

            // Returns true only if both are NULL
            return p==q ;

        // Current values should match
        // Left subtree should match
        // Right subtree should match
        return p->val == q->val &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};