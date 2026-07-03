/*
=========================================================
Problem: Assign Cookies
Link: https://leetcode.com/problems/assign-cookies/
=========================================================
*/

// ---------------------------
// Method 1 : Greedy
// Time Complexity: O(N log N + M log M)
// Space Complexity: O(1)
// ---------------------------

class Solution {
public:
    int findContentChildren(vector<int>& nums1, vector<int>& nums2) {

        // Sort greed factors and cookie sizes.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int ans = 0;

        int child = 0;
        int cookie = 0;

        // Try assigning the smallest possible cookie
        // to each child.
        while(child < nums1.size() && cookie < nums2.size()){

            if(nums2[cookie] >= nums1[child]){

                cookie++;
                child++;
                ans++;
            }
            else{

                cookie++;
            }
        }

        return ans;
    }
};