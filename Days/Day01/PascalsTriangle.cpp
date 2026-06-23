/*
=========================================================
Problem: Pascal's Triangle
Link: https://leetcode.com/problems/pascals-triangle/
=========================================================
*/

// ---------------------------
// Method 1 : Simulation
// Time Complexity: O(N²)
// Space Complexity: O(N²)
// ---------------------------

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> result;

        // The first row of Pascal's Triangle is always {1}.
        result.push_back({1});

        // Generate each row using the previous row.
        for (int i = 1; i < numRows; i++) {

            vector<int> row;

            // First element of every row is always 1.
            row.push_back(1);

            // Compute the middle elements by adding
            // the two elements directly above.
            for (int j = 1; j < i; j++) {
                row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }

            // Last element of every row is always 1.
            row.push_back(1);

            result.push_back(row);
        }

        return result;
    }
};


// ---------------------------
// Method 2 : Optimized Simulation
// Time Complexity: O(N²)
// Space Complexity: O(N²)
// ---------------------------

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        // Generate each row directly.
        for (int i = 0; i < numRows; i++) {

            // Initialize every element as 1.
            vector<int> row(i + 1, 1);

            // Fill the middle elements.
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(row);
        }

        return ans;
    }
};