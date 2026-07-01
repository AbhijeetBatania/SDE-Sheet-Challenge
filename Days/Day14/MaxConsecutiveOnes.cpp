/*
=========================================================
Problem: Max Consecutive Ones
Link: https://leetcode.com/problems/max-consecutive-ones/
=========================================================
*/

// ---------------------------
// Method 1 : Linear Traversal
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0;
        int max = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 1) {
                count = 0;
            }
            else {
                count++;

                if(max < count) max = count;
            }
        }
        return max;
    }
};