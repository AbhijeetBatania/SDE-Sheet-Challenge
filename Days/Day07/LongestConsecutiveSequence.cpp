/*
=========================================================
Problem: Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/
=========================================================
*/

// ---------------------------
// Method 1 : Sorting
// Time Complexity: O(N log N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty())
            return 0;

        // Sort the array to bring consecutive
        // numbers together.
        sort(nums.begin(), nums.end());

        int longest = 1;
        int current = 1;

        for (int i = 1; i < nums.size(); i++) {

            // Ignore duplicate elements.
            if (nums[i] == nums[i - 1])
                continue;

            // Consecutive element found.
            if (nums[i] == nums[i - 1] + 1) {

                current++;
            }
            else {

                // Sequence breaks here.
                longest = max(longest, current);
                current = 1;
            }
        }

        return max(longest, current);
    }
};


// ---------------------------
// Method 2 : Hash Set (Optimal)
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty())
            return 0;

        // Store all unique elements for O(1) lookup.
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {

            // A sequence starts only if
            // the previous number is absent.
            if (st.find(num - 1) == st.end()) {

                int currentNum = num;
                int length = 1;

                // Extend the sequence forward.
                while (st.find(currentNum + 1) != st.end()) {

                    currentNum++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};