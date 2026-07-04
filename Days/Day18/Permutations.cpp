/*
=========================================================
Problem: Permutations
Link: https://leetcode.com/problems/permutations/
=========================================================
*/

// ---------------------------
// Method 1 : Backtracking (Swapping)
// Time Complexity: O(N × N!)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    vector<vector<int>> result;

    void solve(int idx, vector<int>& nums){

        // One permutation is formed.
        if(idx == nums.size()){
            result.push_back(nums);
            return;
        }

        // Fix every element at current position.
        for(int i = idx; i < nums.size(); i++){

            // Choose current element.
            swap(nums[i], nums[idx]);

            solve(idx + 1, nums);

            // Backtrack.
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        solve(0, nums);

        return result;
    }
};


// ---------------------------
// Method 2 : Backtracking + Hash Set
// Time Complexity: O(N × N!)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    vector<vector<int>> result;
    unordered_set<int> st;
    int n;

    void solve(vector<int>& temp, vector<int>& nums) {

        // One permutation is completed.
        if(temp.size() == n) {
            result.push_back(temp);
            return;
        }

        // Try every unused element.
        for(int i = 0; i < n; i++) {

            if(st.find(nums[i]) == st.end()) {

                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(temp, nums);

                // Backtrack.
                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;

        solve(temp, nums);
        return result;
    }
};