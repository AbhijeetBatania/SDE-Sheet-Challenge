/*
=========================================================
Problem: Permutation Sequence
Link: https://leetcode.com/problems/permutation-sequence/
=========================================================
*/

// ---------------------------
// Method 1 : Factorial Number System
// Time Complexity: O(N²)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    string getPermutation(int n, int k) {

        int fact = 1;
        vector<int> nums;

        // Store numbers from 1 to n.
        for(int i = 1; i < n; i++){

            fact = fact * i;
            nums.push_back(i);
        }

        nums.push_back(n);

        // Convert to 0-based indexing.
        k = k - 1;

        string ans = "";

        while(true){

            // Select the appropriate digit.
            ans += to_string(nums[k / fact]);

            nums.erase(nums.begin() + k / fact);

            if(nums.size() == 0)
                break;

            k = k % fact;

            fact = fact / nums.size();
        }

        return ans;
    }
};