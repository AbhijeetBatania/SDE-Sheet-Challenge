/*
=========================================================
Problem: Next Smaller Element
Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
=========================================================
*/

// ---------------------------
// Method 1 : Monotonic Stack
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here

        int n = arr.size();

        vector<int> ans(n);

        // Monotonic increasing stack.
        stack<int> st;

        // Traverse from right to left.
        for(int i = n-1 ; i>=0 ; i--){

            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }
            else
                ans[i] = st.top();

            // Push current element.
            st.push(arr[i]);
        }

        return ans;
    }
};