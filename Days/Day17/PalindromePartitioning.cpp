/*
=========================================================
Problem: Palindrome Partitioning
Link: https://leetcode.com/problems/palindrome-partitioning/
=========================================================
*/

// ---------------------------
// Method 1 : Backtracking
// Time Complexity: Exponential
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {

        // Check whether substring is palindrome.
        while(l < r){

            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void backtrack(string &s, int idx,
                   vector<string> &curr,
                   vector<vector<string>> &result){

        // Entire string has been partitioned.
        if(idx == s.length()){

            result.push_back(curr);
            return;
        }

        // Try every possible partition.
        for(int i = idx; i < s.length(); i++){

            if(isPalindrome(s, idx, i)){

                curr.push_back(s.substr(idx, i - idx + 1));

                backtrack(s, i + 1, curr, result);

                // Backtrack.
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> curr;

        backtrack(s, 0, curr, result);

        return result;
    }
};