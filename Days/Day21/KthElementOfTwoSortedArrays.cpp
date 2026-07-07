/*
=========================================================
Problem: K-th Element of Two Sorted Arrays
Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
=========================================================
*/

// ---------------------------
// Method 1 : Merge Traversal
// Time Complexity: O(M + N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {

        int m = a.size();
        int n = b.size();

        int i = 0;
        int j = 0;
        int idx = 1;

        // Merge until kth element.
        while(i < m && j < n) {

            if(a[i] <= b[j]) {

                if(idx == k)
                    return a[i];

                i++;
            }
            else {

                if(idx == k)
                    return b[j];

                j++;
            }

            idx++;
        }

        while(i < m) {

            if(idx == k)
                return a[i];

            i++;
            idx++;
        }

        while(j < n) {

            if(idx == k)
                return b[j];

            j++;
            idx++;
        }

        return -1;
    }
};