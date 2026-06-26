/*
=========================================================
Problem: Majority Element II
Link: https://leetcode.com/problems/majority-element-ii/
=========================================================
*/

// ---------------------------
// Method 1 : Sorting
// Time Complexity: O(N log N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> result;

        // Sort the array so equal elements become adjacent.
        sort(nums.begin(), nums.end());

        int count = 1;
        int value = nums[0];

        for (int i = 1; i < n; i++) {

            if (nums[i] == nums[i - 1]) {

                count++;
            }
            else {

                // Store the element if its frequency
                // is greater than n/3.
                if (count > n / 3)
                    result.push_back(value);

                value = nums[i];
                count = 1;
            }
        }

        // Check the last element.
        if (count > n / 3)
            result.push_back(value);

        return result;
    }
};


// ---------------------------
// Method 2 : Boyer-Moore Voting Algorithm
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        int candidate1 = 0;
        int candidate2 = 0;

        int count1 = 0;
        int count2 = 0;

        // Find two possible majority candidates.
        for (int num : nums) {

            if (num == candidate1)
                count1++;

            else if (num == candidate2)
                count2++;

            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }

            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }

            else {
                count1--;
                count2--;
            }
        }

        // Verify the candidates.
        count1 = 0;
        count2 = 0;

        for (int num : nums) {

            if (num == candidate1)
                count1++;

            else if (num == candidate2)
                count2++;
        }

        vector<int> result;

        if (count1 > n / 3)
            result.push_back(candidate1);

        if (count2 > n / 3)
            result.push_back(candidate2);

        return result;
    }
};