/*
=========================================================
Problem: 4Sum
Link: https://leetcode.com/problems/4sum/
=========================================================
*/

// ---------------------------
// Method 1 : Sorting + Two Pointers
// Time Complexity: O(N³)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int n = nums.size();

        // Fix the first element.
        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Fix the second element.
            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                // Find remaining two elements.
                while (left < right) {

                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    if (sum == target) {

                        ans.push_back(
                            {nums[i], nums[j],
                             nums[left], nums[right]});

                        // Skip duplicates.
                        while (left < right &&
                               nums[left] == nums[left + 1])
                            left++;

                        while (left < right &&
                               nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }

                    else if (sum < target)
                        left++;

                    else
                        right--;
                }
            }
        }

        return ans;
    }
};