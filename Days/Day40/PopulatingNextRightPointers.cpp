// ------------------------------------------------------------
// Approach - BFS Level Order Traversal
// T.C : O(n)
// S.C : O(n)
//
// Idea:
// Process nodes level by level using a queue.
//
// Steps:
// 1. Push root into queue.
// 2. Process all nodes of the current level.
// 3. Connect every node with the next node in the queue.
// 4. Push children into the queue.
// 5. Repeat for all levels.
//
// Interview Notes:
// q.front() gives the next node of the same level because
// all current-level nodes are already present in the queue.
// ------------------------------------------------------------

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                // Connect current node to next node in the same level
                if (i < n - 1) {
                    curr->next = q.front();
                }

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
        }
        return root;
    }
};