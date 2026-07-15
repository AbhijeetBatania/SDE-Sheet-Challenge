// ------------------------------------------------------------
// Vertical Order Traversal
// T.C : O(n log n)
// S.C : O(n)
//
// Idea:
// Use BFS to assign coordinates.
//
// x -> Vertical level
// y -> Horizontal level
//
// map<x, map<y, multiset>>
//
// map keeps verticals sorted.
// multiset handles duplicate values.
// ------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        map<int, map<int,multiset<int>> > mp;

        queue<pair<TreeNode*,pair<int,int>>> que;
        que.push({root, {0,0}});

        while(!que.empty()){
            auto it = que.front();
            que.pop();

            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mp[x][y].insert(node->val);

            if(node->left != NULL){
                que.push({node->left , {x-1, y+1}});
            }

            if(node->right != NULL){
                que.push({node->right , {x+1, y+1}});
            }
        }

        for(auto it : mp){
            vector<int> col;
            for(auto val : it.second){
                col.insert(col.end() , val.second.begin() , val.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};