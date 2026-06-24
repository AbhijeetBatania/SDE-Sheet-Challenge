/*
=========================================================
Problem: Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/
=========================================================
*/

// ---------------------------
// Method 1 : Three Pointer Approach
// Time Complexity: O(M + N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int point1 = m - 1;
        int point2 = n - 1;

        // Fill nums1 from the end.
        for (int i = m + n - 1; i >= 0; i--) {

            if (point1 >= 0 && point2 >= 0) {

                if (nums1[point1] >= nums2[point2]) {
                    nums1[i] = nums1[point1--];
                }
                else {
                    nums1[i] = nums2[point2--];
                }
            }
            else if (point2 >= 0) {

                nums1[i] = nums2[point2--];
            }
            else {

                nums1[i] = nums1[point1--];
            }
        }
    }
};


// ---------------------------
// Method 2 : Optimized Three Pointer
// Time Complexity: O(M + N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Merge elements from the back.
        while (j >= 0) {

            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};