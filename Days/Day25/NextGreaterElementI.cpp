/*
=========================================================
Problem: Next Greater Element I
Link: https://leetcode.com/problems/next-greater-element-i/
=========================================================
*/

// ---------------------------
// Method 1 : Monotonic Stack
// Time Complexity: O(N + M)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        // Stores next greater element for every number.
        unordered_map<int,int> m;

        // Monotonic decreasing stack.
        stack<int> s;

        // Traverse from right to left.
        for(int i = nums2.size()-1 ; i>=0; i--){

            while(s.size()>0 && s.top()<=nums2[i]){
                s.pop();
            }

            if(s.empty()){
                m[nums2[i]]=-1;
            }
            else{
                m[nums2[i]]= s.top();
            }

            s.push(nums2[i]);
        }

        // Build answer for nums1.
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};