/*
=========================================================
Problem: Reverse Pairs
Link: https://leetcode.com/problems/reverse-pairs/
=========================================================
*/

// ---------------------------
// Method 1 : Merge Sort
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    int merge(vector<int>& nums, int low, int mid, int high) {

        int count = 0;

        // Count reverse pairs before merging.
        int right = mid + 1;

        for (int left = low; left <= mid; left++) {

            while (right <= high &&
                   (long long)nums[left] > 2LL * nums[right]) {

                right++;
            }

            count += right - (mid + 1);
        }

        // Merge two sorted halves.
        vector<int> temp;

        int left = low;
        right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);

            else
                temp.push_back(nums[right++]);
        }

        while (left <= mid)
            temp.push_back(nums[left++]);

        while (right <= high)
            temp.push_back(nums[right++]);

        // Copy merged elements back.
        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];

        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);

        count += merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};