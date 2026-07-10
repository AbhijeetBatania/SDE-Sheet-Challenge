/*
=========================================================
Problem: Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Character by Character Comparison
// Time Complexity: O(N × M)
// Space Complexity: O(1)
// ---------------------------------------------------------

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty())
            return "";

        int i = 0;
        string ans;

        while (i < strs[0].size()) {

            char ch = strs[0][i];

            // Compare current character
            // with every other string
            for (int j = 1; j < strs.size(); j++) {

                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return ans;
                }
            }

            ans += ch;
            i++;
        }

        return ans;
    }
};