/*
=========================================================
Problem: Combination Sum
Link: https://leetcode.com/problems/combination-sum/
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

    void solve(int idx, int sum, vector<int>& candidates, int target, vector<int>& curr){

        // Valid combination found.
        if(sum == target){
            result.push_back(curr);
            return;
        }

        // Invalid case.
        if(sum > target || idx >= candidates.size()){
            return;
        }

        // Include current element.
        curr.push_back(candidates[idx]);
        solve(idx, sum + candidates[idx], candidates, target, curr);

        // Backtrack.
        curr.pop_back();

        // Exclude current element.
        solve(idx + 1, sum, candidates, target, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> curr;

        solve(0, 0, candidates, target, curr);

        return result;
    }
};


// ---------------------------
// Method 2 : Backtracking (For Loop)
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

        // Try every possible candidate.
        for(int i = idx; i < candidates.size(); i++){

            curr.push_back(candidates[i]);

            // Reuse the same element.
            solve(candidates, target - candidates[i], curr, i);

            // Backtrack.
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> curr;

        solve(candidates, target, curr, 0);

        return result;
    }
};