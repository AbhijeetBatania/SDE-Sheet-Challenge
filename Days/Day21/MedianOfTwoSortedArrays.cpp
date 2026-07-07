/*
=========================================================
Problem: Median of Two Sorted Arrays
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
=========================================================
*/

// ---------------------------
// Method 1 : Merge Two Sorted Arrays
// Time Complexity: O(M + N)
// Space Complexity: O(M + N)
// ---------------------------

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> merge;

        int first = 0;
        int second = 0;

        // Merge both sorted arrays.
        while(first != nums1.size() && second != nums2.size())
        {
            if(nums1[first] <= nums2[second])
            {
                merge.push_back(nums1[first]);
                first++;
            }
            else
            {
                merge.push_back(nums2[second]);
                second++;
            }
        }

        // Copy remaining elements.
        while(first != nums1.size())
        {
            merge.push_back(nums1[first]);
            first++;
        }

        while(second != nums2.size())
        {
            merge.push_back(nums2[second]);
            second++;
        }

        // Odd length.
        if(merge.size() % 2 != 0)
        {
            int mid = merge.size()/2;
            return merge[mid];
        }

        // Even length.
        int mid = merge.size()/2;

        double result = (merge[mid-1] + merge[mid]) / 2.0;

        return result;
    }
};


// ---------------------------
// Method 2 : Merge Without Extra Array
// Time Complexity: O(M + N)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int size = m + n;

        int idx1 = (size/2) - 1;
        int idx2 = size/2;

        int element1 = -1;
        int element2 = -1;

        int i = 0;
        int j = 0;
        int k = 0;

        while(i < m && j < n) {

            if(nums1[i] < nums2[j]) {

                if(k == idx1)
                    element1 = nums1[i];

                if(k == idx2)
                    element2 = nums1[i];

                i++;
            }
            else {

                if(k == idx1)
                    element1 = nums2[j];

                if(k == idx2)
                    element2 = nums2[j];

                j++;
            }

            k++;
        }

        while(i < m) {

            if(k == idx1)
                element1 = nums1[i];

            if(k == idx2)
                element2 = nums1[i];

            i++;
            k++;
        }

        while(j < n) {

            if(k == idx1)
                element1 = nums2[j];

            if(k == idx2)
                element2 = nums2[j];

            j++;
            k++;
        }

        if(size % 2 == 1)
            return element2;

        return (element1 + element2) / 2.0;
    }
};