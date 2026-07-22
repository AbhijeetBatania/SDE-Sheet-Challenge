// Approach : Recursion + HashMap
// T.C : O(n)
// S.C : O(n)

class Solution {
public:

    // Stores inorder value -> index mapping
    unordered_map<int, int> mp;

    TreeNode* construct(vector<int>& postorder,
                        vector<int>& inorder,
                        int start,
                        int end,
                        int& idx) {

        // No nodes left to construct
        if(start > end)
            return NULL;

        // Current postorder element becomes root
        int rootVal = postorder[idx];
        idx--;

        // Find root position in inorder traversal
        int i = mp[rootVal];

        TreeNode* root = new TreeNode(rootVal);

        // Build right subtree first
        root->right = construct(postorder, inorder, i+1, end, idx);

        // Build left subtree
        root->left = construct(postorder, inorder, start, i-1, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = postorder.size();

        // Store inorder indices
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        // Start from last element of postorder
        int idx = n - 1;

        return construct(postorder, inorder, 0, n-1, idx);
    }
};