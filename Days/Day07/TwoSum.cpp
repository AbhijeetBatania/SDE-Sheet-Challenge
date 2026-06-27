/*
=========================================================
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/
=========================================================
*/

// ---------------------------
// Method 1 : Hash Map
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            // Check if the required complement
            // has already been seen.
            if (mp.count(target - nums[i]))
                return {mp[target - nums[i]], i};

            // Store current element and its index.
            mp[nums[i]] = i;
        }

        return {};
    }
};