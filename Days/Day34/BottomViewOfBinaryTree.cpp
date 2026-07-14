// ------------------------------------------------------------
// Bottom View of Binary Tree
// T.C : O(n log n)
// S.C : O(n)
//
// Idea:
// Similar to Top View.
//
// The only difference is that every node replaces
// the previous node at the same horizontal distance.
//
// Hence the last node stored becomes the Bottom View.
// ------------------------------------------------------------

class Solution {
  public:
    vector<int> bottomView(Node *root) {
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