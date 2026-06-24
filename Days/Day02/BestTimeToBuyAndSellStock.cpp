/*
=========================================================
Problem: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
=========================================================
*/

// ---------------------------
// Method 1 : Optimal
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {

            // Track the minimum price seen so far.
            minPrice = min(minPrice, prices[i]);

            // Calculate profit if stock is sold today.
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};