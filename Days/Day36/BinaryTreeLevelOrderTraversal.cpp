// Approach : Breadth First Search (Level Order Traversal)
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        // If tree is empty
        if(root == NULL) return {};

        queue<TreeNode*> que;
        vector<vector<int>> ans;

        // Start BFS from root
        que.push(root);

        while(!que.empty()){

            // Number of nodes present at current level
            int n = que.size();

            vector<int> level;

            while(n--){

                TreeNode* node = que.front();
                que.pop();

                // Store current node
                level.push_back(node->val);

                // Push left child
                if(node->left)
                    que.push(node->left);

                // Push right child
                if(node->right)
                    que.push(node->right);
            }

            // Store one complete level
            ans.push_back(level);
        }

        return ans;
    }
};