/*
=========================================================
Problem: Rotate Image
Link: https://leetcode.com/problems/rotate-image/
=========================================================
*/

// ---------------------------
// Method 1 : Using Extra Matrix
// Time Complexity: O(N²)
// Space Complexity: O(N²)
// ---------------------------

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Create a new matrix to store rotated values.
        vector<vector<int>> result(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Place current element in its rotated position.
                result[j][n - i - 1] = matrix[i][j];
            }
        }

        matrix = result;
    }
};


// ---------------------------
// Method 2 : Transpose + Reverse (Optimal)
// Time Complexity: O(N²)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose the matrix.
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse every row.
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};