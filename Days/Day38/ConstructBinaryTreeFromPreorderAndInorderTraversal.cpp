// Approach : Recursion + HashMap
// T.C : O(n)
// S.C : O(n)

class Solution {
public:

    // Stores inorder value -> index mapping
    unordered_map<int, int> mp;

    TreeNode* construct(vector<int>& preorder,
                        vector<int>& inorder,
                        int start,
                        int end,
                        int& idx) {

        // No nodes left
        if(start > end)
            return NULL;

        // Current preorder element becomes root
        int rootVal = preorder[idx];
        idx++;

        // Find root in inorder traversal
        int i = mp[rootVal];

        TreeNode* root = new TreeNode(rootVal);

        // Build left subtree
        root->left = construct(preorder, inorder, start, i-1, idx);

        // Build right subtree
        root->right = construct(preorder, inorder, i+1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        // Build inorder index map
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }

        int idx = 0;

        return construct(preorder, inorder, 0, n-1, idx);
    }
};