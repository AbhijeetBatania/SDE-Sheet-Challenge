/*
=========================================================
Problem: M-Coloring Problem
Link: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
=========================================================
*/

// ---------------------------
// Method 1 : Backtracking
// Time Complexity: O(M^V × V)
// Space Complexity: O(V + E)
// ---------------------------

class Solution {
public:

    // Check whether assigning the current color
    // to this node is valid.
    bool isSafe(int col, int node,
                vector<vector<int>> &graph,
                vector<int> &colors) {

        // Check all adjacent vertices.
        for (int neighbour : graph[node]) {

            if (colors[neighbour] == col)
                return false;
        }

        return true;
    }

    // Backtracking function.
    bool solve(int node, int v, int m,
               vector<vector<int>> &graph,
               vector<int> &colors) {

        // All vertices are colored.
        if (node == v)
            return true;

        // Try every available color.
        for (int col = 1; col <= m; col++) {

            if (isSafe(col, node, graph, colors)) {

                // Assign color.
                colors[node] = col;

                // Color remaining vertices.
                if (solve(node + 1, v, m, graph, colors))
                    return true;

                // Backtrack.
                colors[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {

        // Build adjacency list.
        vector<vector<int>> graph(v);

        for (auto &edge : edges) {

            int u = edge[0];
            int w = edge[1];

            graph[u].push_back(w);
            graph[w].push_back(u);
        }

        // Initially all nodes are uncolored.
        vector<int> colors(v, 0);

        return solve(0, v, m, graph, colors);
    }
};