/*
=========================================================
Problem: 3Sum
Link: https://leetcode.com/problems/3sum/
=========================================================
*/

// ---------------------------
// Method 1 : Sorting + Two Pointers
// Time Complexity: O(N²)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:

    void twoSum(vector<int>& nums, int i, vector<vector<int>>& result, int target) {

        // Two Pointer Technique.
        int j = nums.size() - 1;

        while(i < j) {

            if(nums[i] + nums[j] > target)
                j--;

            else if(nums[i] + nums[j] < target)
                i++;

            else {

                // Skip duplicate elements.
                while(i < j && nums[i] == nums[i + 1])
                    i++;

                while(i < j && nums[j] == nums[j - 1])
                    j--;

                result.push_back({-target, nums[i], nums[j]});

                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        // Less than 3 elements cannot form a triplet.
        if(nums.size() < 3)
            return {};

        vector<vector<int>> result;

        // Sort the array.
        sort(nums.begin(), nums.end());

        // Fix one element and find the remaining two.
        for(int i = 0; i < nums.size() - 2; i++) {

            // Skip duplicate first elements.
            if(i != 0 && nums[i] == nums[i - 1])
                continue;

            twoSum(nums, i + 1, result, -nums[i]);
        }

        return result;
    }
};

// ---------------------------
// Method 2 : Sorting + Two Pointers
// Time Complexity: O(N²)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        int n = arr.size();

        // Sort the array so that two pointers can be used.
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        // Fix the first element of the triplet.
        for (int i = 0; i < n; i++) {

            // Skip duplicate first elements.
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            // Two pointers for the remaining two elements.
            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {

                    // Valid triplet found.
                    ans.push_back({arr[i], arr[left], arr[right]});

                    left++;
                    right--;

                    // Skip duplicate values from the left.
                    while (left < right && arr[left] == arr[left - 1])
                        left++;

                    // Skip duplicate values from the right.
                    while (left < right && arr[right] == arr[right + 1])
                        right--;
                }
                else if (sum < 0) {
                    // Need a larger sum.
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
};