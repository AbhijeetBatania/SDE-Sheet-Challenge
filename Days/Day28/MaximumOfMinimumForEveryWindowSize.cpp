/*
=========================================================
Problem: Maximum of Minimum for Every Window Size
Link: https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Previous Smaller + Next Smaller
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> left(n), right(n);

        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        vector<int> ans(n + 1, 0);

        // Find maximum of minimums for every window length
        for (int i = 0; i < n; i++) {

            int len = right[i] - left[i] - 1;  // Gives the curr element is minimum for which window size

            ans[len] = max(ans[len], arr[i]);
        }

        // Fill remaining entries
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        ans.erase(ans.begin()); // Remove index 0

        return ans;
    }
};