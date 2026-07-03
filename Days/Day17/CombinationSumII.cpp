/*
=========================================================
Problem: Combination Sum II
Link: https://leetcode.com/problems/combination-sum-ii/
=========================================================
*/

// ---------------------------
// Method 1 : Backtracking
// Time Complexity: Exponential
// Space Complexity: O(Target)
// ---------------------------

class Solution {
public:

    vector<vector<int>> result;

    void solve(vector<int>& candidates, int target,
               vector<int>& curr, int idx){

        if(target < 0)
            return;

        if(target == 0){
            result.push_back(curr);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){

            // Skip duplicate elements.
            if(i > idx && candidates[i] == candidates[i - 1])
                continue;

            curr.push_back(candidates[i]);

            solve(candidates, target - candidates[i], curr, i + 1);

            // Backtrack.
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // Sorting groups duplicate values together.
        sort(candidates.begin(), candidates.end());

        vector<int> curr;

        solve(candidates, target, curr, 0);

        return result;
    }
};