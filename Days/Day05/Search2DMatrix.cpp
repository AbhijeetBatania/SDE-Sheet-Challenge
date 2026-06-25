/*
=========================================================
Problem: Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/
=========================================================
*/

// ---------------------------
// Method 1 : Row-wise Search
// Time Complexity: O(M + N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;

        // Find the row where the target can exist.
        for (; row < rows; row++) {

            // Target found at the last element.
            if (matrix[row][cols - 1] == target)
                return true;

            // Stop once the row's last element
            // becomes greater than the target.
            if (matrix[row][cols - 1] > target)
                break;
        }

        // Target is greater than every element.
        if (row == rows)
            return false;

        // Search the selected row from right to left.
        for (int col = cols - 1; col >= 0; col--) {

            if (matrix[row][col] == target)
                return true;

            // Since the row is sorted,
            // no need to continue further.
            if (matrix[row][col] < target)
                return false;
        }
        
        return false;
    }
};


// ---------------------------
// Method 2 : Binary Search (Optimal)
// Time Complexity: O(log(M × N))
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        // Treat the matrix as a sorted 1-D array.
        while (left <= right) {

            int mid = left + (right - left) / 2;

            int row = mid / cols;
            int col = mid % cols;

            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};