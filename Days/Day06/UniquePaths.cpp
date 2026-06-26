/*
=========================================================
Problem: Unique Paths
Link: https://leetcode.com/problems/unique-paths/
=========================================================
*/

// ---------------------------
// Method 1 : Recursion + Memoization
// Time Complexity: O(M × N)
// Space Complexity: O(M × N)
// ---------------------------

class Solution {
public:

    int dp[101][101];

    int solve(int row, int col, int m, int n) {

        // Destination reached.
        if (row == m - 1 && col == n - 1)
            return 1;

        // Out of bounds.
        if (row >= m || col >= n)
            return 0;

        // Return previously computed answer.
        if (dp[row][col] != -1)
            return dp[row][col];

        // Move right.
        int right = solve(row, col + 1, m, n);

        // Move down.
        int down = solve(row + 1, col, m, n);

        return dp[row][col] = right + down;
    }

    int uniquePaths(int m, int n) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, m, n);
    }
};