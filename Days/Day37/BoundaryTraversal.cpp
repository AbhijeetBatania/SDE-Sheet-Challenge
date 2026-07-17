// Approach : Boundary Traversal
// T.C : O(n)
// S.C : O(h)

class Solution {
  public:

    // Checks whether current node is a leaf node
    bool isLeaf(Node* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    // Adds left boundary excluding leaf nodes
    void addLeftBoundary(Node* root, vector<int>& ans) {

        Node* curr = root->left;

        while (curr) {

            if (!isLeaf(curr))
                ans.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    // Adds all leaf nodes
    void addLeaves(Node* root, vector<int>& ans) {

        if (root == NULL)
            return;

        if (isLeaf(root)) {

            ans.push_back(root->data);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    // Adds right boundary in reverse order
    void addRightBoundary(Node* root, vector<int>& ans) {

        vector<int> temp;

        Node* curr = root->right;

        while (curr) {

            if (!isLeaf(curr))
                temp.push_back(curr->data);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        // Reverse right boundary
        for (int i = temp.size() - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        if (!root)
            return ans;

        // Root should be added only if it is not a leaf
        if (!isLeaf(root))
            ans.push_back(root->data);

        // Left Boundary
        addLeftBoundary(root, ans);

        // Leaf Nodes
        addLeaves(root, ans);

        // Right Boundary
        addRightBoundary(root, ans);

        return ans;
    }
};