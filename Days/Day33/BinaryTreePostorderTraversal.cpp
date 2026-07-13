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
// Traverse Left -> Traverse Right -> Visit Root.
//
// This is the standard DFS Postorder Traversal.
// ------------------------------------------------------------

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;

        postorder(root->left, ans);   //left
        postorder(root->right, ans);  //right
        ans.push_back(root->val);     //root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;

    }
};

// ------------------------------------------------------------
// Approach 2 - Iterative Traversal using Stack
// T.C : O(n)
// S.C : O(n)
//
// Idea:
// Postorder = Left -> Right -> Root
//
// Instead of directly generating Postorder,
// generate Root -> Right -> Left
// and finally reverse the answer.
//
// Steps:
// 1. Push root.
// 2. Pop node and store it.
// 3. Push left child.
// 4. Push right child.
// 5. Reverse the final traversal.
//
// This is one of the most common interview approaches.
// ------------------------------------------------------------

// Iterative Solution using Stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            if (curr->left)
                st.push(curr->left);

            if (curr->right)
                st.push(curr->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};