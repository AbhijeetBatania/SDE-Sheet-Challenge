/*
=========================================================
Problem: Stock Span Problem
Link: https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
=========================================================
*/

// ---------------------------------------------------------
// Approach 1 : Monotonic Stack
// Time Complexity: O(N)
// Space Complexity: O(N)
// ---------------------------------------------------------

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {

        stack<pair<int,int>> st;
        vector<int> ans;

        for(int i = 0 ; i < arr.size() ; i++) {

            int span = 1;

            // Merge spans of previous smaller/equal elements
            while(!st.empty() && st.top().first <= arr[i]) {
                span += st.top().second;
                st.pop();
            }

            st.push({arr[i], span});

            ans.push_back(span);
        }

        return ans;
    }
};