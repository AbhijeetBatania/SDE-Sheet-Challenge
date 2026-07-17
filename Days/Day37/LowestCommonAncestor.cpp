// Approach : Recursive DFS
// T.C : O(n)
// S.C : O(h)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base Case
        // If root becomes NULL or one of the nodes is found
        if (root == nullptr || root == p || root == q)
            return root;

        // Search in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If p and q are present in right subtree
        if (left == NULL){
            return right;
        }

        // If p and q are present in left subtree
        else if( right == NULL){
            return left;
        }

        // One node found on left and other on right
        // Hence current node is LCA
        else
            return root;
    }
};