/*
=========================================================
Problem: Coin Change
Link: https://leetcode.com/problems/coin-change/
=========================================================
*/

// ---------------------------
// Method 1 : Recursion + Memoization
// Time Complexity: O(Amount × Number of Coins)
// Space Complexity: O(Amount × Number of Coins)
// ---------------------------

class Solution {
public:

    int dp[13][10001];

    int solve(vector<int>& coins, int amount, int i)
    {
        // Exact amount formed.
        if(amount == 0)
            return 0;

        // Invalid state.
        if(i >= coins.size() || amount < 0)
            return INT_MAX;

        // Return previously computed answer.
        if(dp[i][amount] != -1)
            return dp[i][amount];

        int take = INT_MAX;

        // Choose the current coin.
        if(amount - coins[i] >= 0) {

            int temp = solve(coins, amount - coins[i], i);

            if(temp != INT_MAX)
                take = 1 + temp;
        }

        // Skip the current coin.
        int skip = solve(coins, amount, i + 1);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        memset(dp, -1, sizeof(dp));

        int ans = solve(coins, amount, 0);

        return ans == INT_MAX ? -1 : ans;
    }
};