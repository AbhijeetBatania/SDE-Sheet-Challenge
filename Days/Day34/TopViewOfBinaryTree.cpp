// ------------------------------------------------------------
// Top View of Binary Tree
// T.C : O(n log n)
// S.C : O(n)
//
// Idea:
// Perform Level Order Traversal.
//
// Store every node with its horizontal distance.
//
// The first node encountered at every horizontal
// distance forms the Top View.
// ------------------------------------------------------------

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;

        queue<pair<Node* , int>> que;
        map<int,int> mp;

        que.push({root, 0});

        while(!que.empty()){
            auto it = que.front();
            que.pop();

            Node* node = it.first;
            int line = it.second;

            if(mp.find(line) == mp.end())
                mp[line] = node->data;

            if(node->left != NULL)
                que.push({node->left , line-1});

            if(node->right != NULL)
                que.push({node->right , line+1});
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};