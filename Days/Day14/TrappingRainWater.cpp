/*
=========================================================
Problem: Trapping Rain Water
Link: https://leetcode.com/problems/trapping-rain-water/
=========================================================
*/

// ---------------------------
// Method 1 : Prefix Max Arrays
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        // Less than 2 bars cannot trap water.
        if(n == 1 || n == 0)
            return 0;

        // Stores the maximum height from the left.
        vector<int> leftMax(n);
        leftMax[0] = height[0];

        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Stores the maximum height from the right.
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int sum = 0;

        // Water stored at each index is determined by
        // the smaller of left and right maximum heights.
        for(int i = 0; i < n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }

        return sum;
    }
};