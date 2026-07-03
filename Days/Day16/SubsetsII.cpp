/*
=========================================================
Problem: Subsets II
Link: https://leetcode.com/problems/subsets-ii/
=========================================================
*/

// ---------------------------
// Method 1 : Backtracking
// Time Complexity: O(2^N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    vector<vector<int>> result;

    void solve(vector<int>& curr, vector<int>& nums, int idx){

        // One subset is formed.
        if(idx == nums.size()){

            result.push_back(curr);
            return;
        }

        // Include current element.
        curr.push_back(nums[idx]);

        solve(curr, nums, idx + 1);

        // Backtrack.
        curr.pop_back();

        // Skip duplicate elements.
        int next = idx + 1;

        while(next < nums.size() && nums[next] == nums[idx]){

            next++;
        }

        // Exclude current element.
        solve(curr, nums, next);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Sorting groups duplicate elements together.
        sort(nums.begin(), nums.end());

        vector<int> curr;

        solve(curr, nums, 0);

        return result;
    }
};