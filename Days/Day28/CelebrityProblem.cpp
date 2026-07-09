/*
=========================================================
Problem: Celebrity Problem
Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Count In-degree & Out-degree
// Time Complexity: O(N²)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<int> knowMe(n, 0);
        vector<int> IKnow(n, 0);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if(i!=j && mat[i][j] == 1){
                    knowMe[j]++;
                    IKnow[i]++;
                }
            }
        }

        // Celebrity knows nobody and everyone knows celebrity
        for (int i = 0; i < n; i++) {

            if(knowMe[i] == n-1 && IKnow[i] == 0){
                return i;
            }
        }

        return -1;
    }
};


// ---------------------------------------------------------
// Approach 2 : Two Pointer (Optimal)
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------------------------------------

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {

        int n = mat.size();

        int top = 0;
        int down = n - 1;

        // Find possible celebrity
        while (top < down) {

            if (mat[top][down] == 1) {
                // top knows down, so top is not celebrity
                top++;
            }
            else {
                // top does not know down, so down is not celebrity
                down--;
            }
        }

        int candidate = top;

        // Verify candidate
        for (int i = 0; i < n; i++) {

            if (i == candidate)
                continue;

            // Candidate should know nobody
            if (mat[candidate][i] == 1)
                return -1;

            // Everyone should know candidate
            if (mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};