/*
=========================================================
Problem: Count Inversions
Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
=========================================================
*/

// ---------------------------
// Method 1 : Merge Sort
// Time Complexity: O(N log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    // Merge two sorted halves and count inversions.
    int merge(vector<int>& arr, int start, int mid, int end) {

        vector<int> temp;

        int left = start;
        int right = mid + 1;

        int count = 0;

        while (left <= mid && right <= end) {

            if (arr[left] <= arr[right]) {

                temp.push_back(arr[left]);
                left++;
            }
            else {

                // All remaining elements in the left half
                // form inversions with arr[right].
                count += (mid - left + 1);

                temp.push_back(arr[right]);
                right++;
            }
        }

        // Copy remaining left half.
        while (left <= mid) {

            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining right half.
        while (right <= end) {

            temp.push_back(arr[right]);
            right++;
        }

        // Copy merged elements back.
        for (int i = start; i <= end; i++) {

            arr[i] = temp[i - start];
        }

        return count;
    }

    int mergeSort(vector<int>& arr, int start, int end) {

        if (start >= end)
            return 0;

        int mid = start + (end - start) / 2;

        int count = 0;

        // Count inversions in left half.
        count += mergeSort(arr, start, mid);

        // Count inversions in right half.
        count += mergeSort(arr, mid + 1, end);

        // Count cross inversions.
        count += merge(arr, start, mid, end);

        return count;
    }

    int inversionCount(vector<int>& arr) {

        return mergeSort(arr, 0, arr.size() - 1);
    }
};