/*
=========================================================
Problem: Next Permutation
Link: https://leetcode.com/problems/next-permutation/
=========================================================
*/

// ---------------------------
// Method 1 : Optimal
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Step 1:
        // Find the first element from the end that is
        // smaller than its next element (pivot).
        int pivot = n - 2;

        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
            pivot--;
        }

        // Step 2:
        // Find the smallest element greater than the pivot
        // from the right side and swap them.
        if (pivot >= 0) {

            int j = n - 1;

            while (nums[j] <= nums[pivot]) {
                j--;
            }

            swap(nums[pivot], nums[j]);
        }

        // Step 3:
        // Reverse the suffix to obtain the next
        // lexicographically smallest permutation.
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};