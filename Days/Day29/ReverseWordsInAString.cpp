/*
=========================================================
Problem: Reverse Words in a String
Link: https://leetcode.com/problems/reverse-words-in-a-string/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Traverse String from Back
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {
public:
    string reverseWords(string s) {

        string ans;

        int i = s.size() - 1;

        while (i >= 0) {

            // Skip trailing spaces
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int end = i;

            // Find the beginning of the word
            while (i >= 0 && s[i] != ' ')
                i--;

            // Add space before every word except first
            if (!ans.empty())
                ans += " ";

            ans += s.substr(i + 1, end - i);
        }

        return ans;
    }
};