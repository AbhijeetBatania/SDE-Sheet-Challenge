/*
=========================================================
Problem: Largest Rectangle in Histogram
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Using Next Smaller Left & Next Smaller Right
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> right(n);    // Next Smallest Right
        vector<int> left(n);     // Next smallest left

        stack<int> st;

        // Find Next Smaller Element on Right
        for(int i = 0 ; i < n ; i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {  // check if next ele is smaller
                right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        // No smaller element exists on right
        while(!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }

        // Find Next Smaller Element on Left
        for(int i = n-1 ; i >= 0 ; i--) {

            while(!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        // No smaller element exists on left
        while(!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }

        // Calculate maximum rectangle area
        int ans = 0;

        for(int i = 0 ; i < n ; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }
};


// ---------------------------------------------------------
// Approach 2 : Single Stack (Optimal)
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int ans = 0;
        int n = heights.size();

        stack<int> st;

        for(int i = 0 ; i < n ; i++) {

            while(!st.empty() && heights[st.top()] > heights[i]) {

                int index = st.top();
                st.pop();

                if(!st.empty())
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                else
                    ans = max(ans, heights[index] * i);  // NSR-NSL-1 == NSR-(-1)-1
            }

            st.push(i);
        }

        // Process remaining bars
        while(!st.empty()) {

            int index = st.top();
            st.pop();

            if(!st.empty())
                ans = max(ans, heights[index] * (n - st.top() - 1));
            else
                ans = max(ans, heights[index] * n); // NSR-NSL-1 == NSR-(-1)-1
        }

        return ans;
    }
};