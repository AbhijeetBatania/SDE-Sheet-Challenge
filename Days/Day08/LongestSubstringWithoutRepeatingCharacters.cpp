/*
=========================================================
Problem: Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
=========================================================
*/

// ---------------------------
// Method 1 : Sliding Window + Hash Set
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> window;

        int left = 0;
        int right = 0;

        int longest = 0;

        while (right < s.size()) {

            // Remove characters until the
            // duplicate is removed.
            while (window.find(s[right]) != window.end()) {

                window.erase(s[left]);
                left++;
            }

            // Expand the window.
            window.insert(s[right]);

            longest = max(longest,
                          right - left + 1);

            right++;
        }

        return longest;
    }
};


// ---------------------------
// Method 2 : Sliding Window + Last Occurrence
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Stores the last index of each character.
        vector<int> lastIndex(256, -1);

        int left = 0;
        int longest = 0;

        for (int right = 0; right < s.size(); right++) {

            // If current character already exists
            // inside the current window,
            // move the left pointer.
            if (lastIndex[s[right]] >= left) {

                left = lastIndex[s[right]] + 1;
            }

            // Update last occurrence.
            lastIndex[s[right]] = right;

            longest = max(longest,
                          right - left + 1);
        }

        return longest;
    }
};