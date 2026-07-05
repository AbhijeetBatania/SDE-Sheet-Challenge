/*
=========================================================
Problem: Rat in a Maze
Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
=========================================================
*/

// ---------------------------
// Method 1 : Backtracking
// Time Complexity: O(4^(N×N))
// Space Complexity: O(N×N)
// ---------------------------

class Solution {
public:

    vector<string> ans;

    void solve(int i, int j,
               vector<vector<int>>& maze,
               int n,
               string path) {

        // Invalid position.
        if(i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0){
            return;
        }

        // Destination reached.
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }

        // Mark current cell as visited.
        maze[i][j] = 0;

        // Move Down.
        path.push_back('D');
        solve(i+1, j, maze, n, path);
        path.pop_back();

        // Move Right.
        path.push_back('R');
        solve(i, j+1, maze, n, path);
        path.pop_back();

        // Move Up.
        path.push_back('U');
        solve(i-1, j, maze, n, path);
        path.pop_back();

        // Move Left.
        path.push_back('L');
        solve(i, j-1, maze, n, path);
        path.pop_back();

        // Backtrack.
        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        string path = "";
        int n = maze.size();

        solve(0, 0, maze, n, path);

        // Return paths in lexicographical order.
        sort(ans.begin(), ans.end());

        return ans;
    }
};