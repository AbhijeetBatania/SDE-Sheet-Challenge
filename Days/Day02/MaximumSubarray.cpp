/*
=========================================================
Problem: Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/
=========================================================
*/

// ---------------------------
// Method 1 : Kadane's Algorithm (Optimal)
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maximumSum = INT_MIN;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Add current element to the running sum.
            currentSum += nums[i];

            // Update maximum subarray sum found so far.
            maximumSum = max(maximumSum, currentSum);

            // If running sum becomes negative,
            // start a new subarray.
            if (currentSum < 0)
                currentSum = 0;
        }

        return maximumSum;
    }
};