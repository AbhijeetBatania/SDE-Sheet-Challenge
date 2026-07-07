/*
=========================================================
Problem: Kth Largest Element in an Array
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
=========================================================
*/

// ---------------------------
// Method 1 : Max Heap
// Time Complexity: O((N + K) log N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq;

        // Push all elements into max heap.
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        // Remove largest k-1 elements.
        while(k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};


// ---------------------------
// Method 2 : Min Heap of Size K
// Time Complexity: O(N log K)
// Space Complexity: O(K)
// ---------------------------

class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums) {

            pq.push(num);

            // Keep only k largest elements.
            if(pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};