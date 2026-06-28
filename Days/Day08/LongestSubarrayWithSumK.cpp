/*
=========================================================
Problem: Longest Subarray with Sum K
Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
=========================================================
*/

// ---------------------------
// Method 1 : Prefix Sum + Hash Map
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        unordered_map<long long, int> firstOccurrence;

        long long prefixSum = 0;
        int longest = 0;

        for (int i = 0; i < arr.size(); i++) {

            // Update the running prefix sum.
            prefixSum += arr[i];

            // If prefix sum itself equals k,
            // the subarray starts from index 0.
            if (prefixSum == k)
                longest = i + 1;

            // Find whether (prefixSum - k)
            // has appeared before.
            long long required = prefixSum - k;

            if (firstOccurrence.find(required) != firstOccurrence.end()) {

                longest = max(longest,
                              i - firstOccurrence[required]);
            }

            // Store only the first occurrence
            // to maximize subarray length.
            if (firstOccurrence.find(prefixSum) ==
                firstOccurrence.end()) {

                firstOccurrence[prefixSum] = i;
            }
        }

        return longest;
    }
};