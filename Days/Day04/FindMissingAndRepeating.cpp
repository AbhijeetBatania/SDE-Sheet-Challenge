/*
=========================================================
Problem: Find Missing and Repeating
Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
=========================================================
*/

// ---------------------------
// Method 1 : Frequency Encoding
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(2);

        // Convert array values to 0-based indexing.
        for (int i = 0; i < n; i++) {
            arr[i]--;
        }

        // Increase the value at the corresponding index
        // by n to encode the frequency.
        for (int i = 0; i < n; i++) {
            arr[arr[i] % n] += n;
        }

        // Decode the frequencies.
        for (int i = 0; i < n; i++) {

            // Frequency 0 -> Missing number.
            if (arr[i] / n == 0)
                ans[1] = i + 1;

            // Frequency 2 -> Repeating number.
            if (arr[i] / n == 2)
                ans[0] = i + 1;
        }

        return ans;
    }
};


// ---------------------------
// Method 2 : Cyclic Sort
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        int n = arr.size();
        int i = 0;

        // Place every element at its correct index.
        while (i < n) {

            int correctIndex = arr[i] - 1;

            if (arr[i] != arr[correctIndex]) {
                swap(arr[i], arr[correctIndex]);
            }
            else {
                i++;
            }
        }

        // The misplaced element is the repeating number,
        // while its index represents the missing number.
        for (i = 0; i < n; i++) {

            if (arr[i] != i + 1)
                return {arr[i], i + 1};
        }

        return {-1, -1};
    }
};