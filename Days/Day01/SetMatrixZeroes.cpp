/*
=========================================================
Problem: Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes/
=========================================================
*/

// ---------------------------
// Method 1 : Brute Force
//Time Complexity: O(M × N × (M + N))
//Space Complexity: O(M × N)
// ---------------------------

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Temporary matrix to mark cells that should become zero
        vector<vector<int>> temp(rows, vector<int>(cols, 1));

        // Mark the corresponding row and column whenever a zero is found
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == 0) {

                    // Mark entire row
                    for (int k = 0; k < cols; k++)
                        temp[i][k] = 0;

                    // Mark entire column
                    for (int k = 0; k < rows; k++)
                        temp[k][j] = 0;
                }
            }
        }

        // Update the original matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (temp[i][j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
};


// ---------------------------
// Method 2 : Optimal
//Time Complexity: O(M × N)
//Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Store row and column information
        // using first row and first column
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == 0) {

                    if (i == 0)
                        firstRowZero = true;

                    if (j == 0)
                        firstColZero = true;

                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Fill inner matrix based on markers
        for (int i = 1; i < rows; i++) {

            for (int j = 1; j < cols; j++) {

                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Update first row if required
        if (firstRowZero)
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;

        // Update first column if required
        if (firstColZero)
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
    }
};