/*
=========================================================
Problem: Single Element in a Sorted Array
Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
=========================================================
*/

// ---------------------------
// Method 1 : Binary Search
// Time Complexity: O(log N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Make mid even.
            if (mid % 2 == 1)
                mid--;

            // Pair is correct.
            if (nums[mid] == nums[mid + 1])
                low = mid + 2;

            // Single element lies on left.
            else
                high = mid;
        }

        return nums[low];
    }
};