/*
=========================================================
Problem: Search in Rotated Sorted Array II (Extra)
Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
=========================================================
*/

// ---------------------------
// Method 1 : Binary Search
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    bool search(vector<int>& arr, int x) {

        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == x)
                return true;

            // Unable to determine sorted half.
            if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
                start++;
                end--;
            }

            // Left half sorted.
            else if (arr[start] <= arr[mid]) {

                if (arr[start] <= x && x < arr[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }

            // Right half sorted.
            else {

                if (arr[mid] < x && x <= arr[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};