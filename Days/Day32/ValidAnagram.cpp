/*
=========================================================
Problem: Valid Anagram
Link: https://leetcode.com/problems/valid-anagram/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Frequency Array
// Time Complexity : O(n)
// Space Complexity : O(1)
// ---------------------------------------------------------

class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, they cannot be anagrams
        if (s.length() != t.length())
            return false;

        // Store frequency difference of every character
        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // Every frequency should become zero
        for (int count : freq) {
            if (count != 0)
                return false;
        }

        return true;
    }
};