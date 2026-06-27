/*
=========================================================
Problem: 3Sum
Link: https://leetcode.com/problems/3sum/
=========================================================
*/

// ---------------------------
// Method 1 : Sorting + Two Pointers
// Time Complexity: O(N²)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    void twoSum(vector<int>& nums,
                int left,
                vector<vector<int>>& result,
                int target) {

        int right = nums.size() - 1;

        while (left < right) {

            int sum = nums[left] + nums[right];

            if (sum < target)
                left++;

            else if (sum > target)
                right--;

            else {

                result.push_back({-target, nums[left], nums[right]});

                // Skip duplicate elements.
                while (left < right &&
                       nums[left] == nums[left + 1])
                    left++;

                while (left < right &&
                       nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        if (nums.size() < 3)
            return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; i++) {

            // Skip duplicate first elements.
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            twoSum(nums, i + 1, result, -nums[i]);
        }

        return result;
    }
};


// ---------------------------
// Method 2 : Optimized Two Pointers
// Time Complexity: O(N²)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    ans.push_back(
                        {nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate pairs.
                    while (left < right &&
                           nums[left] == nums[left - 1])
                        left++;

                    while (left < right &&
                           nums[right] == nums[right + 1])
                        right--;
                }

                else if (sum < 0)
                    left++;

                else
                    right--;
            }
        }

        return ans;
    }
};