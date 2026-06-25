/*
=========================================================
Problem: Find the Duplicate Number
Link: https://leetcode.com/problems/find-the-duplicate-number/
=========================================================
*/

// ---------------------------
// Method 1 : Sorting
// Time Complexity: O(N log N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Sort the array so duplicate elements become adjacent.
        sort(nums.begin(), nums.end());

        // Traverse the sorted array and
        // return the first repeated element.
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] == nums[i - 1])
                return nums[i];
        }

        return -1;
    }
};


// ---------------------------
// Method 2 : Frequency Array
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();

        // Frequency array to count occurrences.
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {

            freq[nums[i]]++;

            // Duplicate found when frequency becomes 2.
            if (freq[nums[i]] == 2)
                return nums[i];
        }

        return -1;
    }
};


// ---------------------------
// Method 3 : Floyd's Cycle Detection (Optimal)
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Initialize slow and fast pointers.
        int slow = nums[0];
        int fast = nums[0];

        // Move slow by one step and fast by two steps
        // until they meet inside the cycle.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Move one pointer back to the beginning.
        // The point where they meet again
        // is the duplicate number.
        slow = nums[0];

        while (slow != fast) {

            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};