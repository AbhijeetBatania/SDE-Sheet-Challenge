// ------------------------------------------------------------
// Approach - Recursion + Divide and Conquer
// T.C : O(n)
// S.C : O(log n)
//
// Idea:
// Choose the middle element as root so that the left and
// right portions contain approximately equal elements.
//
// Steps:
// 1. Find middle element.
// 2. Create it as root.
// 3. Recursively construct left subtree.
// 4. Recursively construct right subtree.
//
// Interview Notes:
// Choosing the middle element guarantees a height-balanced BST
// for a sorted array.
// ------------------------------------------------------------

class Solution {
public:
    TreeNode* solve(vector<int>& nums, int l, int r) {
        if (l > r)
            return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(nums, l, mid - 1);
        root->right = solve(nums, mid + 1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};