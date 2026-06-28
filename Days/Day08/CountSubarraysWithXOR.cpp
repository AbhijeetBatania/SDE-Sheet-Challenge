/*
=========================================================
Problem: Count Subarrays with Given XOR
Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
=========================================================
*/

// ---------------------------
// Method 1 : Prefix XOR + Hash Map
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    long subarrayXor(vector<int>& arr, int k) {

        unordered_map<int, int> freq;

        // Empty prefix has XOR = 0.
        freq[0] = 1;

        int prefixXor = 0;
        int count = 0;

        for (int num : arr) {

            // Compute prefix XOR.
            prefixXor ^= num;

            // Find the required XOR value.
            int required = prefixXor ^ k;

            // Add all previous occurrences.
            if (freq.find(required) != freq.end()) {

                count += freq[required];
            }

            // Store current prefix XOR.
            freq[prefixXor]++;
        }

        return count;
    }
};