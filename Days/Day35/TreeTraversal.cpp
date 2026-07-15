// ------------------------------------------------------------
// Single Stack Traversal
// T.C : O(n)
// S.C : O(n)
//
// Idea:
// We use a stack storing {node, state}.
//
// state = 1 -> Preorder
// state = 2 -> Inorder
// state = 3 -> Postorder
//
// Each node is pushed at most 3 times.
// ------------------------------------------------------------

vector<vector<int>> getTreeTraversal(TreeNode *root) {

    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

    if(root == NULL)
        return {inorder, preorder, postorder};

    stack<pair<TreeNode*, int>> st;

    st.push({root, 1});

    while(!st.empty()) {

        auto it = st.top();
        st.pop();

        // Preorder
        if(it.second == 1) {

            preorder.push_back(it.first->data);

            it.second++;
            st.push(it);

            if(it.first->left)
                st.push({it.first->left, 1});
        }

        // Inorder
        else if(it.second == 2) {

            inorder.push_back(it.first->data);

            it.second++;
            st.push(it);

            if(it.first->right)
                st.push({it.first->right, 1});
        }

        // Postorder, it.second == 3
        else {

            postorder.push_back(it.first->data);
        }
    }

    return {inorder, preorder, postorder};
}