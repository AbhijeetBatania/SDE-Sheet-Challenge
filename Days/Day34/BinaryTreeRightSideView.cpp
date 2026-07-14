// ------------------------------------------------------------
// Approach 1 - Breadth First Search (Level Order Traversal)
// T.C : O(n)
// S.C : O(n)
//
// Idea:
// Traverse the tree level by level.
// The last node processed at every level is visible
// from the right side.
// ------------------------------------------------------------

//BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            TreeNode* temp = NULL;

            while(n--){
                temp = que.front();
                que.pop();

                if(temp->left != NULL)  
                    que.push(temp->left);

                if(temp->right != NULL)   // you can push temp->right before temp->left to get left side view
                    que.push(temp->right);
            }
            ans.push_back(temp->val);   // last node of the level will be the rightmost node of that level
        }
        return ans;
    }
};

// ------------------------------------------------------------
// Approach 2 - Depth First Search
// T.C : O(n)
// S.C : O(h)
//
// Idea:
// Traverse Right subtree before Left subtree.
//
// Whenever we visit a level for the first time,
// that node is the rightmost node of that level.
// ------------------------------------------------------------

// DFS
class Solution {
public:
    void preorder(int level, TreeNode* root, vector<int> &ans){
        if(root == NULL) return;

        if(ans.size() < level){
            ans.push_back(root->val);
        }

        preorder(level+1, root->right , ans);   // you can push temp->left before temp->right to get left side view
        preorder(level+1, root->left , ans);

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(1, root , ans);
        return ans;
    }
};