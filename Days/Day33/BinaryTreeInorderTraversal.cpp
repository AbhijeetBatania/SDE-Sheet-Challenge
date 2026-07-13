// ------------------------------------------------------------
// Approach 1 - Recursive Traversal
// T.C : O(n)
// S.C : O(h)
//
// h = Height of the tree.
// O(log n) for balanced tree.
// O(n) for skewed tree.
//
// Idea:
// Traverse Left -> Root -> Right.
// This is the most basic DFS traversal.
// ------------------------------------------------------------

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;

        inorder(root->left, ans);    // Left
        ans.push_back(root->val);    // Root
        inorder(root->right, ans);   // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2 - Iterative Traversal Using Stack
// T.C : O(n)
// S.C : O(h)
//
// Idea:
// Instead of recursion, explicitly maintain the recursion stack.
//
// Steps:
// 1. Keep moving left while pushing nodes.
// 2. When left becomes NULL,
//    process the node.
// 3. Move to its right subtree.
// ------------------------------------------------------------

// Iterative Solution Using Stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (true) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } 
            else {
                if(st.empty() == true) break;

                curr = st.top();
                st.pop();

                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 3 - Morris Traversal (Tree Modification)
// T.C : O(n)
// S.C : O(1)
//
// Idea:
// Traverse without recursion and stack.
//
// This approach temporarily modifies the tree by removing
// left pointers after creating temporary links.
//
// NOTE:
// This version changes the tree structure,
// so it is generally NOT preferred in interviews.
// ------------------------------------------------------------

// Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* leftchild = curr->left;

                while(leftchild->right != NULL){
                    leftchild = leftchild->right;
                }

                leftchild->right = curr;

                TreeNode* temp = curr; 
                curr = curr->left;
                temp->left = NULL; // removing left pointer so that we dont stuck in loop
            }
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 4 - Morris Traversal (Threaded Binary Tree)
// T.C : O(n)
// S.C : O(1)
//
// Idea:
// Create temporary threads from inorder predecessor
// to the current node.
//
// Steps:
// 1. If left child doesn't exist,
//    visit current node.
// 2. Otherwise find inorder predecessor.
// 3. If thread doesn't exist,
//    create it and move left.
// 4. If thread already exists,
//    remove it, visit current node,
//    then move right.
//
// This is the standard Morris Traversal
// asked in coding interviews because
// it restores the original tree.
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