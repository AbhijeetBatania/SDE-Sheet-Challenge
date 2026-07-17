// Approach-1 : BFS + Reverse Alternate Levels
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // Empty tree
        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        // false -> Left to Right
        // true  -> Right to Left
        bool flag = 0;

        while (!q.empty()) {

            int n = q.size();

            vector<int> temp;

            while (n--) {

                TreeNode* node = q.front();
                q.pop();

                // Store current node
                temp.push_back(node->val);

                // Push left child
                if (node->left)
                    q.push(node->left);

                // Push right child
                if (node->right)
                    q.push(node->right);
            }

            // Reverse alternate levels
            if (flag == 1)
                reverse(temp.begin(), temp.end());

            ans.push_back(temp);

            // Toggle direction
            flag = !flag;
        }

        return ans;
    }
};

// Approach-2 : BFS without Reverse
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // Empty tree
        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int n = q.size();

            // Allocate space for current level
            vector<int> level(n);

            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Compute index based on traversal direction
                int index = leftToRight ? i : (n - 1 - i);

                level[index] = node->val;

                // Push left child
                if (node->left)
                    q.push(node->left);

                // Push right child
                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(level);

            // Toggle direction
            leftToRight = !leftToRight;
        }

        return ans;
    }
};