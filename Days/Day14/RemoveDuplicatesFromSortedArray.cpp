/*
=========================================================
Problem: Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
=========================================================
*/

// ---------------------------
// Method 1 : Two Pointer
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Empty array.
        if(nums.empty())
            return 0;

        // Points to the position where
        // the next unique element will be placed.
        int index = 1;

        for(int i = 1; i < nums.size(); i++) {

            // Copy only unique elements.
            if(nums[i] != nums[i - 1]) {

                nums[index++] = nums[i];
            }
        }

        return index;
    }
};

// ---------------------------
// Method 2 : Using Set
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        int k = st.size();
        int j = 0;

        for (int x : st) {
            nums[j++] = x;
        }
        return k;
    }
};