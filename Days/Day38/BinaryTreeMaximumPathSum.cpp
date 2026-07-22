// Approach : Postorder DFS
// T.C : O(n)
// S.C : O(h)

class Solution {
public:
    int maxSum;

    // Returns the maximum path sum starting from current node
    // and extending to only one of its children
    int solve(TreeNode* root) {

        // Base Case
        if(root == NULL)
            return 0;

        // Maximum path sum from left subtree
        int l = solve(root->left);

        // Maximum path sum from right subtree
        int r = solve(root->right);

        // Case 1:
        // Path passes through current node using both children
        int neeche_hi_milgaya_answer = l + r + root->val;

        // Case 2:
        // Choose the better child
        int koi_ek_acha = max(l, r) + root->val;

        // Case 3:
        // Start a completely new path from current node
        int only_root_acha = root->val;

        // Update global answer
        maxSum = max({maxSum,
                      neeche_hi_milgaya_answer,
                      koi_ek_acha,
                      only_root_acha});

        // Return only one branch to parent
        return max(koi_ek_acha, only_root_acha);
    }

    int maxPathSum(TreeNode* root) {

        maxSum = INT_MIN;

        solve(root);

        return maxSum;
    }
};