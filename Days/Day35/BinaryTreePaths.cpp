// ------------------------------------------------------------
// Root to Leaf Paths
// T.C : O(n)
// S.C : O(h)
//
// Idea:
// DFS + Backtracking.
//
// Keep building the current path.
// Whenever a leaf node is reached,
// store the path.
// ------------------------------------------------------------

class Solution {
public:
    void solve(TreeNode* node, string &path, vector<string> &ans) {
    if (node == NULL) return;

    int len = path.size();

    if (!path.empty())
        path += "->";

    path += to_string(node->val);

    if (node->left == NULL && node->right == NULL)
        ans.push_back(path);
    else {
        solve(node->left, path, ans);
        solve(node->right, path, ans);
    }

    path.resize(len); // backtrack
}

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        solve(root, path , ans);
        return ans;
    }
};