/*
=========================================================
Problem: Median in a Row Wise Sorted Matrix
Link: https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
=========================================================
*/

// ---------------------------
// Method 1 : Binary Search + STL Upper Bound
// Time Complexity: O(32 * N * log M)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int median(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        // Find global minimum and maximum.
        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int required = (n * m) / 2;

        while (low < high) {

            int mid = low + (high - low) / 2;

            int count = 0;

            // Count elements <= mid.
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (count <= required)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};


// ---------------------------
// Method 2 : Binary Search + Custom Upper Bound
// Time Complexity: O(32 * N * log M)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    int upperBound(vector<int> &row, int x) {

        int low = 0;
        int high = row.size();

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (row[mid] <= x)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }

    int median(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int required = (n * m) / 2;

        while (low < high) {

            int mid = low + (high - low) / 2;

            int count = 0;

            for (int i = 0; i < n; i++) {
                count += upperBound(mat[i], mid);
            }

            if (count <= required)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};