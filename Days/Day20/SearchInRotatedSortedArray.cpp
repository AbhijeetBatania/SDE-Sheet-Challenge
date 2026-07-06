/*
=========================================================
Problem: Search in Rotated Sorted Array
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
=========================================================
*/

// ---------------------------
// Method 1 : Binary Search
// Time Complexity: O(log N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while(start <= end){

            int mid = start + (end - start) / 2;

            if(nums[mid] == target)
                return mid;

            // Left half is sorted.
            if(nums[start] <= nums[mid]){

                if(nums[start] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }

            // Right half is sorted.
            else{

                if(nums[mid] < target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};