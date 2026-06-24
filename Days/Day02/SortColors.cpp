/*
=========================================================
Problem: Sort Colors
Link: https://leetcode.com/problems/sort-colors/
=========================================================
*/

// ---------------------------
// Method 1 : Counting Sort (Two Pass)
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zero = 0;
        int one = 0;
        int two = 0;

        // Count occurrences of 0s, 1s and 2s.
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                zero++;

            else if (nums[i] == 1)
                one++;

            else
                two++;
        }

        int index = 0;

        // Fill all 0s.
        while (zero--)
            nums[index++] = 0;

        // Fill all 1s.
        while (one--)
            nums[index++] = 1;

        // Fill all 2s.
        while (two--)
            nums[index++] = 2;
    }
};


// ---------------------------
// Method 2 : Dutch National Flag Algorithm
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            // Place 0 in the left partition.
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            // 1 is already in its correct partition.
            else if (nums[mid] == 1) {
                mid++;
            }

            // Place 2 in the right partition.
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};