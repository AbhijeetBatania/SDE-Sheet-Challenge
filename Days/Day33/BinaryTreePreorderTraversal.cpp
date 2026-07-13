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
// Visit Root -> Traverse Left -> Traverse Right.
// This is the basic DFS Preorder Traversal.
// ------------------------------------------------------------

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;

        ans.push_back(root->val);    //root
        preorder(root->left, ans);   //left
        preorder(root->right, ans);  //right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2 - Iterative Traversal using Stack
// T.C : O(n)
// S.C : O(h)
//
// Idea:
// Stack simulates recursion.
//
// Steps:
// 1. Push root.
// 2. Pop current node.
// 3. Visit node.
// 4. Push right child first.
// 5. Push left child.
//
// Left is processed first because stack is LIFO.
// ------------------------------------------------------------

// Iterative Solution using Stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            if (curr->right)
                st.push(curr->right);

            if (curr->left)
                st.push(curr->left);
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
// This version modifies the original tree by
// redirecting pointers.
//
// NOTE:
// Not generally preferred because the original
// tree structure gets changed.
// ------------------------------------------------------------

// Morris Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                ans.push_back(curr->val);   // Visit before going left

                TreeNode* leftchild = curr->left;

                while (leftchild->right != NULL) {
                    leftchild = leftchild->right;
                }

                leftchild->right = curr->right;

                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
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
// Create temporary threads to inorder predecessor.
//
// Difference from inorder Morris:
// Node is visited BEFORE moving to left subtree.
//
// Steps:
// 1. If no left child -> Visit node.
// 2. Else find predecessor.
// 3. Create temporary thread.
// 4. Visit node.
// 5. Move left.
// 6. Remove thread while returning.
//
// This is the standard Morris Preorder Traversal.
// ------------------------------------------------------------

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    // Visit before going left
                    ans.push_back(curr->val);
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    // Remove thread
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};