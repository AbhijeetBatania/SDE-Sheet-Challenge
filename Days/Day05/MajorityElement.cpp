/*
=========================================================
Problem: Majority Element
Link: https://leetcode.com/problems/majority-element/
=========================================================
*/

// ---------------------------
// Method 1 : Moore's Voting Algorithm
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Choose a new candidate when count becomes zero.
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }

            // Same candidate increases the vote count.
            else if (nums[i] == candidate) {
                count++;
            }

            // Different element cancels one vote.
            else {
                count--;
            }
        }

        return candidate;
    }
};