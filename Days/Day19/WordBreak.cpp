/*
=========================================================
Problem: Word Break
Link: https://leetcode.com/problems/word-break/
=========================================================
*/

// ---------------------------
// Method 1 : Recursion + Memoization
// Time Complexity: O(N³)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    unordered_set<string> st;

    int t[301];

    int n;

    bool solve(string &s, int idx) {

        // Entire string has been segmented.
        if(idx == n)
            return true;

        // Remaining substring itself is a word.
        if(st.find(s.substr(idx, n - idx)) != st.end()) {
            return true;
        }

        // Memoized answer.
        if(t[idx] != -1)
            return t[idx];

        // Try every possible substring.
        for(int l = 1; l <= n; l++) {

            string temp = s.substr(idx, l);

            if(st.find(temp) != st.end() && solve(s, idx + l)){

                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        n = s.length();

        memset(t, -1, sizeof(t));

        // Store dictionary words.
        for(string &word : wordDict){
            st.insert(word);
        }

        return solve(s, 0);
    }
};