// ------------------------------------------------------------
// Maximum Width of Binary Tree
// T.C : O(n)
// S.C : O(n)
//
// Idea:
// Perform Level Order Traversal.
//
// Assign an index to every node like
// Complete Binary Tree.
//
// Left Child  -> 2*i + 1
// Right Child -> 2*i + 2
//
// Width = lastIndex - firstIndex + 1
//
// Normalize indices at every level to
// avoid integer overflow.
// ------------------------------------------------------------

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , long long>> que;
        long long ans = 0;
        if(root == NULL) return 0;

        que.push({root, 0});

        while(!que.empty()){
            long long left = que.front().second;
            long long right = que.back().second;

            ans = max(ans, right-left+1);

            int n = que.size();
            while(n--){
                auto it = que.front();
                que.pop();

                TreeNode* node = it.first;
                long long idx = it.second - left;  // Normalize

                if(node->left)
                    que.push({node->left , 2*idx +1});

                if(node->right)
                    que.push({node->right , 2*idx +2});
            }
        }
        return ans;
    }
};