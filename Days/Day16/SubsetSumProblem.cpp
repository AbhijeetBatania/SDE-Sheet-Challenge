/*
=========================================================
Problem: Subset Sum Problem
Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
=========================================================
*/

// ---------------------------
// Method 1 : Recursion + Memoization
// Time Complexity: O(N × Sum)
// Space Complexity: O(N × Sum)
// ---------------------------

class Solution {
public:

    int dp[201][10001];

    bool solve(int i, int sum, vector<int>& arr) {

        // Required sum formed.
        if(sum == 0)
            return true;

        // No elements left.
        if(i == arr.size())
            return false;

        // Invalid sum.
        if(sum < 0)
            return false;

        // Return memoized answer.
        if(dp[i][sum] != -1)
            return dp[i][sum];

        // Include current element.
        bool take = solve(i + 1, sum - arr[i], arr);

        // Exclude current element.
        bool skip = solve(i + 1, sum, arr);

        return dp[i][sum] = take || skip;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        memset(dp, -1, sizeof(dp));

        return solve(0, sum, arr);
    }
};